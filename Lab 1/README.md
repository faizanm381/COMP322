README: Lab 1 (Time and Forking Children) - COMP322 - Faizan Mohammed 

Project Status: Complete

Log/Progress Notes:

Entry 1: Overall Progress throughout the week (2/22/20 - 2/29/20)

While looking over the guidelines to follow for Lab1, I tried understanding and playing around with the functions provided in the
description; time(2), fork(2), etc. I started by setting up the output for time since its easier to do first. Learning the difference 
between time() and times() took time to understand since I had user/system time result in 0, but in Slack you stated that it is acceptable. Next I started on learning how to create a parent and child process via fork() and how to output parent/child based on the usage example in the lab1 guideline. It took some time for me to understand how and where to use waitpid()/wait() for the parent to wait for the child. I used it after the parent had displayed its PPID/PID and placed a wait() for the child to display it PPID/PID. During that wait, I  retrieved the return value of the child if it had one by retrieving the child's exit status after the wait with WIFEXITED(). An if statement is used to check if the child had a valid return value and outputs the CPID and retval. The code's output looks acceptable based on your example on Slack. This lab assignment was easier to do than lab0, unless I am doing something wrong that doesn't follow the way the fork should be handled/presented.

Entry 2: Last minute changes after Slack notifications (2/29/20)

After the Slack notifications today, I had adjusted the code/readme to the way you wanted it presented; removed return(0), 
elucidating unique functions used in the program in readme, and using more than one function other than main().
