all: spiritd moles
.PHONY: all
	
spiritd: spiritd.c
	gcc -c spiritd.c -Wall -Wextra
	gcc -o spiritd spiritd.c -lm -lpthread -lrt
	
moles: moles.c
	gcc -c moles.c -Wall -Wextra
	gcc -o moles moles.c -lm
	
clean:
	-rm -f spiritd moles
	