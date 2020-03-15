Log/Progress Notes:

Entry 1: Completing launch (3/12/20)

	I started off the project by using my code from Lab 1, since I needed to work with forking again in this lab assignment. Creating
the makefile was somewhat confusing since there are alot of makefile targets in this lab and had to understand what all and clean did.
After that, I played around the system calls understanding how they work before I run them in launch. I tried getting /bin/ls to work
in execve() and it took a while to understand what argv and envp do in the function. After learning how to utilize the process imaging, I
modified argv in the child process as stated in the lab guideline and took that argv and assigned it newargv for process imaging. Next I
had to figure out how to get the child's pid to the parent process. I used a pipe to get the child pid by writing the child's pid in the
child process and read the value in the parent process.