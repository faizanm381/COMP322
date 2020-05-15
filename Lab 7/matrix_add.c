#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <aio.h>
#include <errno.h>

time_t stSeconds, enSeconds;

void matrix_add(struct aiocb* block, int size, int scalar);
struct aiocb createIoRequest(int fd, off_t offset, size_t length);

int main(int argc, char* argv[]){
	
	int totalTime = 0;
	stSeconds = time(NULL);
	int scalar = rand() % 100;
	int block = atoi(argv[argc-1]);
	int size = atoi(argv[argc-2]);
	int blockSize = size / block;
	//struct aiocb last, current, next;
	struct aicob matrix, controlBlock;
	
	if(size % block != 0){
		fprintf(stderr, "Error: size & block are unevenly divided\n");
		exit(0);
	}
	
	for(int x = 1; block > x; x++){
		for(int y = 1; block > y; y++){
			matrix = createIoRequest(0, 0, blockSize);
			aio_read(&matrix);
			while (aio_error(&matrix) == EINPROGRESS);
		}					
	}

	//char buffer[BUFFERSIZE];
    //fgets(buffer, BUFFERSIZE , stdin);
    //printf("Read: %s", buffer);

	enSeconds = time(NULL);
	totalTime = enSeconds - stSeconds;
	
	fprintf(stderr, "Total Time: %d\n", totalTime);
	fprintf(stderr, "Scalar Value: %d\n", scalar);
}

void matrix_add(struct aiocb* block, int size, int scalar){
	
	for(int i = 1; i < size; i++){
		for(int j = 1; j < size; j++){
				block[i][j] += scalar;			
		}
	}
	
}

struct aiocb createIoRequest(int fd, off_t offset, size_t length){
	
    struct aiocb ret = {0};{
        ret.aio_fildes = fd;
        ret.aio_offset = offset;
        ret.aio_buf = malloc(length);
        ret.aio_nbytes = length;            
    }
	
    return ret;
}