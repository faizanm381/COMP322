#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <signal.h>

static int count = 0;
static int termCount = 0;

char* sigList[64] = {"HUP", "INT", "QUIT", "ILL", "TRAP", "ABRT", "EMT", "FPE", "KILL", "BUS", "SEGV", "SYS", "PIPE",
"ALRM", "TERM", "URG", "STOP", "TSTP", "CONT", "CHLD", "TTIN", "TTOU", "IO", "XCPU", "XFSZ", "VTALRM", "PROF", "WINCH",
"PWR", "USR1", "USR2", "RTMIN", "RTMIN+1", "RTMIN+2", "RTMIN+3", "RTMIN+4", "RTMIN+5", "RTMIN+6", "RTMIN+7", "RTMIN+8",
"RTMIN+9", "RTMIN+10", "RTMIN+11", "RTMIN+12", "RTMIN+13", "RTMIN+14", "RTMIN+15", "RTMIN+16", "RTMAX-15", "RTMAX-14",
"RTMAX-13", "RTMAX-12", "RTMAX-11", "RTMAX-10", "RTMAX-9", "RTMAX-8", "RTMAX-7", "RTMAX-6", "RTMAX-5", "RTMAX-4",
"RTMAX-3", "RTMAX-2", "RTMAX-1", "RTMAX",};

time_t stSeconds;

void sigHandler(int);

int main (int argc, char *argv[]) {
	
	stSeconds = time(NULL);
   
	printf("START: %ld\n", stSeconds);
	
	fprintf(stderr, "catcher: $$ = %d\n", getpid());
	
	for(int i = 1; argc > i; i++){
		
		for (int j = 0; 64 > j; j++){
			
			if(strcmp(argv[i], sigList[j]) == 0){
				signal(j+1, sigHandler);
			}
		}
	}

    while(1){
		pause();
    }
}

void sigHandler(int signum) {
	stSeconds = time(NULL);
	count++;
	
	if(signum == 15){
		termCount++;
	}
	else{
		termCount = 0;
	}
	
	if(signum == 1){
		signum = 0;
	}
	else{
		signum -= 1;
	}
	
	printf("SIG%s caught at %ld\n", sigList[signum], stSeconds);
	
	if(termCount == 3){
		fprintf(stderr, "catcher: Total signals count = %d", count);
		exit(EXIT_SUCCESS);
	}

}
