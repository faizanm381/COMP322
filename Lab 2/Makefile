all: launch tube
.PHONY: all
	
launch: launch.c
	gcc -c launch.c -Wall -Wextra
	gcc -o launch launch.c -lm
	
tube: tube.c
	gcc -c tube.c -Wall -Wextra
	gcc -o tube tube.c -lm
	
clean:
	-rm -f launch tube
	