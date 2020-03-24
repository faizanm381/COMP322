Project Status: Complete

Log/Progress Notes:

Entry 1: Playing around with signals (3/20/20) - (3/22/20)

	I started off the assignment by playing around with signals first and understanding what they do. I went through articles/blogpost
that discussed how to catch and handle signals which were difficult to understand. The only signal I was able to catch was CTRL+C which was
SIGINT(2). I am not sure how to catch the other signals such as USR1/USR2. I decided to wait for more people to question/discuss the lab 
assignment later on Slack while I played around with handling signals.

Entry 2: Finalizing/Completing (3/23/20)
	
	After reading the questions/comments on Slack, I had a better understanding on how to approach the handling for signals such as using
a char array. Not sure if this will be frowned upon, but I had hardcoded the signal names into the char array to get the signal from the 
command args. I used a nested loop to see which signals to check for and put them into signal() when called for. I still was not able to 
understand how to catch other signals like TERM or USR1. I had tested the code with signals that can be used from keyboard shortcuts, like 
CTRL+C (SIGINT) and CTRL+\ (SIGQUIT). Since I could work with 2 signals, I was able to test whether the code would work or not when catching 
three consecutive signals. I catched the signals by using their respective enumerators from the kill -l list. Overall, this lab assignment 
was somewhat confusing to grasp at first, but I now I know how to handle signals by doing it the hardcoded way.