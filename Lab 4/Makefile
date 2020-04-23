all: dining-p 
.PHONY: all
	
dining-p: dining-p.c
	gcc -c dining-p.c -Wall -Wextra
	gcc -o dining-p dining-p.c -lm -lpthread -lrt
	
clean:
	-rm -f dining-p
	