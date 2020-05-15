all: matrix_gen matrix_add
.PHONY: all
	
matrix_gen: matrix_gen.c
	gcc -c matrix_gen.c -Wall -Wextra
	gcc -o matrix_gen matrix_gen.c -lm 
	
matrix_add: matrix_add.c
	gcc -c matrix_add.c -Wall -Wextra
	gcc -o matrix_add matrix_add.c -lm
	
clean:
	-rm -f matrix_gen matrix_add
	