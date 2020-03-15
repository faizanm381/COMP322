#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[]) {
	int stat, nC = 0, io[2], cPid = 0; 	
	char* newargv[] = { NULL };
    char* newenviron[] = { NULL };

	pipe(io);
	
    pid_t childpid = fork(); 
    if (childpid == 0) { 
	
		cPid = getpid();
		write(io[1], &cPid, sizeof(cPid));

		if(argc != 2){
			for(int i = 1; argc > i; i++){
				newargv[nC] = argv[i];
				nC++;
			}
			newargv[nC++] = NULL;
		}		

		execve(argv[1], newargv, newenviron);
    }
	else{
		
		read(io[0], &cPid, sizeof(pid_t));
		fprintf(stderr, "%s: $$ = %d\n", argv[1], cPid);

		wait(&stat);
		
		if(WIFEXITED(stat)){
			int retval = WEXITSTATUS(stat);
			fprintf(stderr, "%s: $? = %d\n", argv[1], retval);
		}
		
	}
}
