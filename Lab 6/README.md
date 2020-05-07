Project Status: Complete (Only completed part 1 and 2)

Log/Progress Notes:

Entry 1: Part 1: Daemon Preparation (4/30/20)

I start by reading through what daemons to learn about what this lab is about. Daemons are long-running processes with no control
terminal, which might be challenging since I can't play around with it due to lack of interaction. I start the first part by constructing
a daemon process through the instructions provided in the lab along with the specified functions. Closing the unneeded file descriptors,
I used close() to get rid of the fds since its more simple to use than getrlimit(). After mimicing the daemon process, I move towards part
2 of the assignment to handle signals and child processes and output the info towards lab6.log file created by program mole. I created
signals to catch in daemon for SIGTERM, SIGUSR1, SIGUSR2. I made the pid childProcess1 & 2 to be declared static so process can be created
in both the signalHandler() and in the daemon process. I wasn't sure if this would work since processes 1 and 2 are randomly spawned from 
either USR1 or USR2 so I will use one pid to fork process when signaled. I created argv[] to store the program to run and the process 
number so moles.c can append the data to the log file. I had pNum take the process number created by using the rand() to get either 
process 1 or 2. I converted pNum to a char to store the process number into argv[] using sprintf() I had the child process fork when
USR1 and USR2 are signaled and use execv() to run moles to output the poped moles from argv[] to the lab6.log file. I then created moles.c 
to figure out whether the program creates/appends to the log file and it works as it writes the home directory "~/lab6.log". Signaling 
SIGUSR1 and SIGUSR2 works and updates the log file with each mole popped.
