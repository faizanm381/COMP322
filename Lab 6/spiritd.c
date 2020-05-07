#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

void sigHandler(int);

static pid_t cp;
static int pNum;

int main(){
	
	int fd;
	pid_t pid;
	
	pid = fork();
	
	if (pid < 0){
		printf("fork failed!\n");
		exit(1);
	}
	
	if (pid > 0){	
		printf("process_id of child process %d \n", pid);
		exit(0);
	}
	
	umask(0);
	
	if(setsid() < 0){
		exit(1);
	}
	
	chdir("/");
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	fd = open("/dev/null",O_RDWR);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	
	signal(SIGTERM, sigHandler);
	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);

	while (1){
		sleep(1);
	}

	return (0);
}

void sigHandler(int signum) {
	
	char processNumber[5];
	
	if(signum == SIGTERM){
		kill(cp, SIGTERM);
		exit(0);
	}
	
	if(signum == SIGUSR1){
		if(pNum == 1){
			kill(cp, SIGTERM);
		}
		
		pNum = (rand() % 2) + 1;
		sprintf(processNumber, "%d", pNum);
		char* argv[] = {"moles", processNumber};
		
		cp = fork();
		
		if(cp == 0){
			execv(argv[0], argv);
		}
		
	}
	
	if(signum == SIGUSR2){
		if(pNum == 2){
			kill(cp, SIGTERM);
		}
		
		pNum = (rand() % 2) + 1;
		sprintf(processNumber, "%d", pNum);
		char* argv[] = {"moles", processNumber};
		
		cp = fork();
		
		if(cp == 0){
			execv(argv[0], argv);
		}
	}

}

	
	
	
	