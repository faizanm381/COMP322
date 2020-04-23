#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <semaphore.h>
#include <errno.h>
#include <fcntl.h>

void eat(int);
void think(int);

void sigHandler(int);
void killChild();

//static int unsigned count = 0;
static int unsigned numOfChair = 0;
static int unsigned philChair = 0;
static int unsigned chopstickAvailable = 0;
static int philCycle[100];

#define LEFT "/leftC"
#define RIGHT "/rightC"

sem_t* semLeft;
sem_t* semRight;
pid_t childpid;

int main (int argc, char *argv[]) {
	
	unsigned int i = 0;
	numOfChair = atoi(argv[1]);
	philChair = atoi(argv[argc-1]);
	chopstickAvailable = numOfChair - 1;
	
	semLeft = sem_open(LEFT, O_CREAT, 0644, chopstickAvailable);
	semRight = sem_open(RIGHT, O_CREAT, 0644, chopstickAvailable);

	for(i = 0; i < numOfChair; i++){
		childpid = fork();
		if(childpid < 0){
			sem_unlink(LEFT);
			sem_unlink(RIGHT);
			sem_close(semLeft);
			sem_close(semRight);
		}
		else if(childpid == 0){
			break;
		}	
	}
	
	
	semLeft = sem_open(LEFT, 0);
	semRight = sem_open(RIGHT, 0);
	
	do{	
		sem_wait(semLeft);
		sem_wait(semRight);
		
		eat(i);
		
		sem_post(semLeft);
		sem_post(semRight);

		think(i);
		
		philCycle[i]++;
		
		signal(15, sigHandler);

	}while(1);
}

void eat(int pNum) {
	printf("Philosopher %d is eating\n", pNum);
	usleep(rand() % 800000 + 100000);
}

void think(int pNum) {
	printf("Philosopher %d is thinking\n", pNum);
	usleep(rand() % 800000 + 100000);
}

void killChild(){
    kill(childpid,SIGKILL);
}

void sigHandler(int signum) {

	if(signum == 15){	
	
		sem_unlink(LEFT);
		sem_unlink(RIGHT);
		sem_close(semLeft);
		sem_close(semRight);
		sem_destroy(semLeft);
		sem_destroy(semRight);
		
		for(unsigned int j = 0; numOfChair > j; j++){
			fprintf(stderr, "Philosopher #%d has completed %d cylces\n", j, philCycle[j]);
		}
		
		exit(EXIT_SUCCESS);
	}

}