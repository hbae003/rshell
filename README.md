rshell
======

Description
-----------

A shell is a program that takes the user's input from the keyboard and lets the user control the operating system. The shell is a text only user interface for Linux and other Unix like operating systems. It is the most fundamental way for a user to interact with the computer. The shell executes the commands and display the output on the screen.

This is a simple program called "rshell", it reproduces the terminal in Linux. When "rshell" is compiled and ran, it will act as another terminal. Basically a terminal within a terminal. It has a command prompt with the currently logged in user and the hostname of the machine followed by a "$".


This is a simple shell designed for unix. The program can take in basic shell commands such as: 
- ls (-a, -l, -la, -al, -l -a, -a -l)
- mkdir
- rmdir
- touch 
- rm
- vim
- cat
- pwd
- script
- exit

The command that had been executed will show up on the screen. Once the user is done, the user needs to type "exit" to exit the program.

The program can also take in connector commands such as: 
- ; 
- &&
- || 

The test Command
------------------

The rshell program has the test command and its symbolic equivalent, [ ]. The test command returns 0 (TRUE) if the test
succeeds. It returns 1 (FALSE) if the test fails. The flags for the test command in the program are:

- -e checks if the file/directory exists
- -f checks if the file/directory exists and is a regular file
- -d checks if the file/directory exists and is a directory

Instead of test, you can just put the flag and path in the [  ]. The default will be the -e flag if you do not input any flags


List of known Bugs
------------------

- Throws an error when not given a real executable command
- Throws an error when given improper connectors (ex &&&, |||) 
- cd command does not work
- Host name cannot be larger than 200 characters
- \# cannot be a name of file or echoed

