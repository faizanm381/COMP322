#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void printRetVal(int stat1, int stat2);

int main (int argc, char *argv[]) {
	int stat1, stat2, nC = 0, nC2 = 0, io1[2], cPipe[2], cPid1 = 0, cPid2 = 0, cmCheck = 0; 	
	char* comma = ",";
	char* argv2;
	char* newargv[] = { NULL };
    char* newenviron[] = { NULL };
	char* newargv2[] = { NULL };
	
	pipe(io1);
	pipe(cPipe);
	
    pid_t childpid = fork(), childpid2; 
	
    if (childpid == 0) { 		//Child 1
	
		cPid1 = getpid();
		write(io1[1], &cPid1, sizeof(cPid1));
		
		if(argc != 2){
			for(int i = 1; argc > i; i++){
				if(strcmp(argv[i], comma) == 0){
					break;
				}
				newargv[nC] = argv[i];
				nC++;
			}
			newargv[nC++] = NULL;
		}
			
		close(cPipe[0]);
		close(cPipe[1]);
		
		dup2(cPipe[1], 1);

			
		execve(argv[1], newargv, newenviron);
    }
	
	else{
	
		childpid2 = fork();
		
		if(childpid2 == 0){		//Child 2
		
			cPid2 = getpid();
			write(io1[1], &cPid2, sizeof(cPid2));
			
			if(argc != 2){
				for(int i = 1; argc > i; i++){
					if(cmCheck > 0){
						newargv2[nC2] = argv[i];
						nC2++;
					}
					if(strcmp(argv[i], comma) == 0){
						cmCheck++;
						argv2 = argv[i+1];
					}
				}
				newargv2[nC2++] = NULL;
			}		
			
			close(cPipe[1]);
			close(cPipe[0]);
			
			dup2(cPipe[0], 0);

			execve(argv2, newargv2, newenviron);			
		}
		
		else{			//Parent
		
			close(cPipe[0]);
			close(cPipe[1]);
			
			read(io1[0], &cPid1, sizeof(pid_t));
			read(io1[0], &cPid2, sizeof(pid_t));
			close(io1[0]);
			close(io1[1]);
			fprintf(stderr, "CPID1: $$ = %d\n", cPid1);
			fprintf(stderr, "CPID2: $$ = %d\n", cPid2);

			
			waitpid(childpid, &stat1, 0);
			waitpid(childpid2, &stat2, 0);
			
			printRetVal(stat1, stat2);
			
		}
	}
}

void printRetVal(int stat1 , int stat2){
	fprintf(stderr, "CPID1: $? = %d\n", stat1);
	fprintf(stderr, "CPID2: $? = %d\n", stat2);
}



