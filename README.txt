Introduction:
This program checks whether the sentence entered by a user is Pangram and/or Tautogram. If it is not a Pangram, it displays the missing letters.

Compiling the program:
The program can be compiled using the terminal with "gcc" and using appropriate flags which are '-std=c99', '-pedantic' and '-Wall'. The exact code to compile it is:
"gcc a4.c -std=c99 -Wall -pedantic"

Running the program:
Program can be run using the terminal and entering './a.out' once we are in the Assignment 4 directory. When it starts, it asks for an input. When the user inputs his/her sentence, it checks whether it is a pangram. If it is, it displays that it is a pangram. If it is not, it displays that it is not a pangram and also displays the missing letter from the sentence. After that, it chekcs if the sentence is a tautogram and then displays the appropriate message.

Limitations:
The program is only tested on the pi system and is not guaranteed to work on other systems. The program also only supports a sentence with a maximum of 300 characters. Anything over that limit will be ignored and the program will keep running.

