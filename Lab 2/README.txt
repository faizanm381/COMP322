Log/Progress Notes:

Entry 1: Completing launch (3/12/20)

	I started off the project by using my code from Lab 1, since I needed to work with forking again in this lab assignment. Creating
the makefile was somewhat confusing since there are alot of makefile targets in this lab and had to understand what all and clean did.
After that, I played around the system calls understanding how they work before I run them in launch. I tried getting /bin/ls to work
in execve() and it took a while to understand what argv and envp do in the function. After learning how to utilize the process imaging, I
modified argv in the child process as stated in the lab guideline and took that argv and assigned it newargv for process imaging. Next I
had to figure out how to get the child's pid to the parent process. I used a pipe to get the child pid by writing the child's pid in the
child process and read the value in the parent process.

Entry 2: Completing tube (3/14/20 - 3/15/20)

	First off I tried to get both child processes to run the system calls and execute in order. After that I had tried to learn the
significance of piping and how it works when communicating between two processes. It took a while to understand the proper way of piping
between them since I had one process work and the other does not. During that learning process, I was stumped for a long time on why my
code was not noticing the comma between the system calls. My issue was comparing them in a if statement using == which doesn't catch it.
So I then used strcmp since that works with char*. This part of the program took a while to complete due to lack of knowledge in comparsions
and how to workaround piping/dup2.

