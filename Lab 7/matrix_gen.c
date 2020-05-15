#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char* argv[]){
	
	int num = atoi(argv[argc-1]), randnum = 0;
	
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
				randnum = rand() % 200 - 100;
				printf("%d", randnum);
				
				if(j != (num - 1)){
					printf(" ");
				}
		}
		if(i != (num - 1)){
			printf("\n");
		}
	}

	return (0);
}

	