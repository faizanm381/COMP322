#include <stdio.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void printSysTime();

int main () {
	int stat; 
	time_t stSeconds;

	stSeconds = time(NULL);
   
	printf("START: %ld\n", stSeconds);
   
    pid_t childpid = fork(); 
    if (childpid == 0) { 
		printf("PPID: %d, PID: %d, ", getppid(), getpid());
    }
	else{
		printf("PPID: %d, PID: %d\n", getppid(), getpid());
		
		wait(&stat);
		
		if(WIFEXITED(stat)){
			int retval = WEXITSTATUS(stat);
			printf("CPID: %d, RETVAL: %d\n", getppid(), retval);
		}
		
		printSysTime();
	}
}


void printSysTime(){
	time_t enSeconds;
	struct tms timeInfo;
	
	times(&timeInfo);
	
	printf("USER: %ld, SYS: %ld\n", timeInfo.tms_utime, timeInfo.tms_stime);
	printf("CUSER: %ld, CSYS: %ld\n", timeInfo.tms_cutime, timeInfo.tms_cstime);
	
	enSeconds = time(NULL);
   
	printf("STOP: %ld\n", enSeconds);
}
