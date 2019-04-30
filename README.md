# Homework 4

Don't cheat. Good luck!

Edit by Kushal: 

For my Homework 4, I have just one Makefile located in the root directory for all 3 coding portion of the HW. I have followed all the requirements in regards to executable and data structure names, except where it has not been specified (for part 3). I have three seperate folders for each part, named part_2, part_3, and part_4. I also have the cse320_print function located in each of the three folders. To compile my code please do the following: 

Program 1, Part 2:
The purpose of program 1 in part 2 is to produce the fibonacci number of any given integer (>0) using multithreading (in which we calculate the fibonacci number in a seperate thread)

To test, proceed to the root directory (i.e. kdelhiwala@kushal:~/cse320/hw4-kdelhiwala). Once in the root directory, please type "make progfib". This will compile the code. To run it, please type "./hw4_progfib N", where N is the number you want to calculate the fibonacci of. Click enter. The result should be the fibonacci of the number you inputted (N). 

Program 2, Part 2: 
The purpose of program 2 in part 2 is to take in 3 files and calculate the number of times 0, 1, and 2 show up in the files. This is calculated in each file using three sepeate threads. 

Proceed to the root directory (i.e. kdelhiwala@kushal:~/cse320/hw4-kdelhiwala). Once in the root directory, please type "make progcnt". This will compile the code. To run it, please type "./hw4_progcnt". Click enter. The result will be in the requested form as per the homework document. Note: Please ensure that the files are located in the root directory, and with the correct name. Otherwise, the program will throw an error. 

Program 3, Part 2: 
The purpose of program 3 in part 3 is to be able to run parallel quicksort. 

Proceed to the root directory (i.e. kdelhiwala@kushal:~/cse320/hw4-kdelhiwala). Once in the root directory, please type "make progqsort". This will compile the code. To run it, please type "./hw4_progqsort filename.dat". You must include the filename, or the program will throw an error and exit. Please press enter to get the result of the sorted array from the file. 

Part 3: 
The purpose of this part was to recreate the last homework, and complete it using multi-threading. This program is a shell that simulates the hiring and firing of artists, using threads. 

Proceed to the root directory (i.e. kdelhiwala@kushal:~/cse320/hw4-kdelhiwala). Once in the root directory, please type "make prevhw" (note: we were not given a name, so this is what I chose). This will compile the code. To run it, please type "./hw4_prevhw". Click enter. This will prompt the shell. Once you are in the shell, please type any of the valid commands (help, hire, fire, fireall, list, exit) to test as you please. 

Part 4:
The purpose of this part is to emulate the movements of people in 5 art museums in Stony Brook. When executed, the program opens a shell that lets a user emulate this. 
 
Proceed to the root directory (i.e. kdelhiwala@kushal:~/cse320/hw4-kdelhiwala). Once in the root directory, please type "make museum_overseer". This will compile the code. To run it, please type "./hw4_museum". Click enter. This will prompt the shell. Once you are in the shell, please type any of the valid commands (in, out, info, start, exit) to test as you please. 

Additional Notes: 

Please note that in my program (part 3 and part 4), I have chosen to keep the threads alive after creating them (I don't join them right away). Once they are "fired" or "kicked out" depending on the program, I close the threads. Another note is I just have one Makefile for all three parts; hence I ask you to be in the root directory whilst making the program. 
