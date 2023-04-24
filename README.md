This is the creation of a simply shell that takes user inputs (commands with arguments) and displays an output accordingly.

Basic loop of a shell :

Print input
Read a line from a standa input (solution)
Turn the command lines string into an executable program
Execute


Files contents card_index_dividers
files	content
Authors	List of contributors to this project
Readme	The README file
Shell.h	The header file
main.c	File that contain the main code
execute.c	File contain the execute functions
path.c	File that contain the path functions
split.c	File that contain the split functions
_realloc.c	Function containing realloc
getenv.c	Function contain env functions
functions.c	Function that contain builtins

Simple Shell shell
the prompt is displayed each time a command has been executed
This program displays a prompt and wait for user type a command
When the user type EXIT, shell will end and exit the interface
The program print the current environement when user type ENV
The program execute the most commun shell commands such as

LS
PWD
CD
EXIT
ENV
History ... with arguments

The program quit when the user enter CTRL + C
The user could stop the program using CTRL + DThis is a readme file showing what the code does
