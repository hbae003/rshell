rshell
======

Description
-----------

This is a simple shell designed for unix. The program can take in basic shell commands such as: 
- ls
- mkdir
- touch 
- rm

The program can also take in connector commands such as: 
- ; 
- &&
- || 

List of known Bugs
------------------

- Throws an error when not given a real executable command
- Throws an error when given improper connectors (ex &&&, |||) 
- Some connectors fail with improper arguments (ex rm nonexistentfile || cmd)
- cd command does not work
- Host name cannot be larger than 200 characters
- # cannot be a name of file or echoed
- || does not work if used consecutively more than twice

