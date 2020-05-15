README: Lab 0 (Making Sense of Ones and Zeroes) - COMP322 - Faizan Mohammed 

Project Status: Complete

Log/Progress Notes:

(2/6/20 - 2/11/20)

I have not coded in C in almost 2 years. I first started with understanding I/O, functions, and error-handling command-line arugments in C. I spent most of my time on this lab relearning the utilities and limitations of C. I had 2 different ways to open files(fopen(), open()) and went with open() since it would be easier to use with the required read(). I read the .txt file or stdin into my buffer and searched for a way to split the data from the buffer. I found using tokens; strtok(), to be the solution to split the data and retrieve the data for them in a function. I pass each token being read into the binaryConversion(); handling the padding for binaries less than 8, converting binary to decimal, outputting decimal character to the corresponding ASCII character, and count # of 1's for parity. All the data will be outputted through this function.

(2/12/20 - 2/15/20)

After learning more about the requirements for Lab 0, I had removed the option to prompt the user for input on error. I have added mnemonics from isascii to use and display for decimals from 0-32 and 127. So far everything works well when using the example input from cat.txt, the only small issue is that the user input must have the input in ascending to descending order, otherwise it would just print nulls after digits that are not 8. I have tried pinpointing the issue and seems that strtok is causing this issue. I resorted to strtok_r but that still had the same issue. I tried pinpointing the issue and it might have something to do with how delicate strtok's elements should be handled with strcat/strncat (null terminator?). The program functions fine with regular input with 8 digits, but has some inconsistency in lower digit values.

(2/16/20)

I tried various inputs to see where the program messed up reading and found that adding a '-' to seperate the input would allow
digits lower than 8 to be read into my binaryConversion(). So I replaced a space for '-' in my buf array to get around this issue.

