Project Status: Complete

Log/Progress Notes:

Entry 1: Starting off the project (4/28/20)
	First I read through the highlighted sections for this lab, specifically 9.3 to 9.5 to get a better understanding of what the
programming assignment is about. I started by allowing input to be entered and error checked for only 2 arguments to be entered in command
line. The first command for the virtual memory address is to be 32bit so I used an unsigned int to hold that number as I convert argv[1] to
that data type with atoi(). Since the page size to be in 4KB, I divided the virtual address number by 4096 (4KB = 4096 bits) to obtain it 
in its specified size. I did the same for the offset, obtaining the remainder when converted to 4KB. Both page size and offset values are 
stored in unsigned int as specified in the lab assignment and mentioned in Slack. I tested the example input in the lab assignment and the 
output corresponds to both. 