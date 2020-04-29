#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void errCheck(int);

int main(int argc, char* argv[]){
	
	unsigned int addressNum, pageNum, offNum;

	errCheck(argc);
	
	addressNum = atoi(argv[1]);
	
	pageNum = addressNum / 4096;
	
	offNum = addressNum % 4096;
	
	printf("The address %d contains: page number: %d offset: %d", addressNum, pageNum, offNum);
	
}

void errCheck(int argc){
	if(argc != 2){
	printf("Fatal Error: Too many args entered");
	exit(0);
	}
}