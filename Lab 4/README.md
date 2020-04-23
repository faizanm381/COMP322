Project Status: Complete (Only completed part 1 and 2)

Log/Progress Notes:

Entry 1: Building part 1 (4/17/20) - (4/22/20)

I started the assignment by building the program from the directions from part 1 of the lab and it was going pretty smooth. I had a
hard time utilizing the semaphore functions and was confused on how they work. I watched a few videos on the significance of semaphores and
why they are used which helped me grasped a better understanding that they allow processes to work and synchronization while following the
rules of the program. I used a for loop to generate processes from fork to allow philsophers to spawn. Each process was able to output the
think and eat functions respectively. I allocated a semaphore for chopsticks to allow philosophers to eat and the processes were 
cooperating. I had issues where the processes would freeze and nothing would show up meaning I had errors in calling sem_wait(). There seems
to be an issue where the first parameter of sem_open() (the name of the semaphore) would cause it to freeze if that same name is used
multiple times. I learned that I didn't destroy the semaphore when signaling SIGTERM, which caused a memory leak. I only implemented
sem_close and sem_unlink at first, by realizing the mistake of forgetting destroy, I learned it the hard way.

Entry 2: Enforcing part 2 (4/23/20)

For the second part of the lab, I tried looking into critical section but it was confusing me, so I went with the circular wait 
option recommeded in the lab where we would need to change the algorithm by creating new conditions for philosophers to dine without deadlock.
I went with having left chopstick picked up first and then right chopstick. If there is no left/right chopstick available, the philosopher
would have to wait for the others to finish. Only issue that I can't figure out is whether the the count of cycles is properly outputted.
Since I'm using cygwin, I can experiment with the SIGINT signal (CTRL+C) to end the program but the output is messy to understand whether
the output is correct. SIGTERM kills all processes which I do not know how to issue in cygwin so hopefully all processes spawned by the
fork are killed and display the count output properly.
