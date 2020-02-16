#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> //pausing

void binaryConversion(char *binary);


int main(int argc, char *argv[]){
	int i, fd = 0, bCount = 0;
	char buf[100];
	char* tokenHolder[100];
	char* reserve = NULL;
	char* delims = " -";
	char* a, * b, * sp = " ";
	
	fd = open(argv[1], O_RDONLY);
	
	//Error-checking for input
	if(argv[1] == NULL){
		printf( "Empty input. Exiting program.\n");
		exit(0);
	}
	
	else if(!strcmp(argv[1], "-") && argc < 3){
		printf( "Invalid input entered '-'. Exiting program.\n");
		exit(0);
	}
	
	//Combining cmd-line args 
	else if (argc != 2){	
		for(i = 1; i < argc; i++){
			if(i == 1){
				a = argv[i];
				b = argv[i+1];
				i++;
			}
			else{
				b = argv[i];
			}
			strcat(a, sp);
			strcat(a, b);	
		}
		strcpy(buf, a);
    }
	
	//File management
	else if(fd == -1){
		printf( "File cannot be found. Exiting program.\n");
		exit(0);
		}
	 
	else{
		read(fd, buf, 100);	
		close(fd);
	}
	
	close(fd);
		
	printf("buf: %s\n", buf);
		
	printf("Original ASCII    Decimal  Parity\n");
	printf("-------- -------- -------- --------\n");
		
	tokenHolder[bCount] = strtok_r(buf, delims, &reserve);
	
	while(tokenHolder[bCount] != NULL){
		bCount++;
		tokenHolder[bCount] = strtok_r(NULL, delims, &reserve);
	}
	
	for(int j = 0; j < bCount; j++){	
		binaryConversion(tokenHolder[j]);
	}
	
    return 0;
}	

void binaryConversion(char *binary){
		int binaryLength = 0;
		int bInt = 0, rem = 0, dec = 0, var = 1, leftBit = 0, par = 0;
		char* binaryHolder = binary;
		char* del = "DEL";
		char* mne[33] = {"NULL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT",
		"LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN",
		"ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "SPACE"};
		char* parResult = "";
		
		printf("original %s\n", binaryHolder);
		
		
		binaryLength = strlen(binaryHolder);

		if(binaryLength == 8){
			bInt = atoi(binaryHolder);
		}
		else if (binaryLength == 7){
			bInt = atoi(binaryHolder);
			strncat(binaryHolder, "0", 1);
			}
		else{
			for(;binaryLength < 8; binaryLength++){
				strncat(binaryHolder, "0", 1);
			}
			bInt = atoi(binaryHolder);
		}
		
		
	
		while(bInt > 0){
			rem = bInt % 10;
			
			if(rem == 1){
				par++;
			}
			
			if(leftBit == 7){
				break;
			}
			
			dec += rem * var;
			bInt /= 10;
			var *= 2;
			leftBit++;
		}
		
		if(par % 2 == 0){
			parResult = "EVEN";
		}
		else{
			parResult = "ODD";
		}

		if((dec >= 0) && (dec <= 32)){
			printf("%s %s\t  %d       %s\n", binaryHolder, mne[dec], dec, parResult);
		}
		else if (dec ==  127){
			printf("%s %s\t  %d       %s\n", binaryHolder, del, dec, parResult);
		}
		else{
			printf("%s %c\t  %d       %s\n", binaryHolder, toascii(dec), dec, parResult);
		}
}


