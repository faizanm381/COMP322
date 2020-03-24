all: catcher 
.PHONY: all
	
catcher: catcher.c
	gcc -c catcher.c -Wall -Wextra
	gcc -o catcher catcher.c -lm
	
clean:
	-rm -f catcher
	