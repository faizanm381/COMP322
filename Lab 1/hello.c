#include <stdio.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main () {
	int stat; 
	struct tms timeInfo;	
	time_t stSeconds, enSeconds;

	stSeconds = time(NULL);
   
	printf("START: %ld\n", stSeconds);
   
    pid_t childpid = fork(); 
    if (childpid == 0) 
    { 
		printf("PPID: %d, PID: %d, ", getppid(), getpid());
    }
	else{
		printf("PPID: %d, PID: %d\n", getppid(), getpid());
		
		wait(&stat);
		
		if(WIFEXITED(stat)){
			int retval = WEXITSTATUS(stat);
			printf("CPID: %d, RETVAL: %d\n", getppid(), retval);
		}
		
		times(&timeInfo);
	
		printf("USER: %ld, SYS: %ld\n", timeInfo.tms_utime, timeInfo.tms_stime);
		printf("CUSER: %ld, CSYS: %ld\n", timeInfo.tms_cutime, timeInfo.tms_cstime);
	
		enSeconds = time(NULL);
   
		printf("STOP: %ld\n", enSeconds);
	
	}
	
	return(0);
}
