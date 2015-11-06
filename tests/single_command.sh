Script started on Fri 06 Nov 2015 11:00:28 AM PST
[hbae003@hammer src]$ ./a.out
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ ls -a
.  ..  a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ ls			-a
.  ..  a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ mkdir			  hello
hbae003@hammer.cs.ucr.edu$ ls
a.out  hello  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ rm hello
rm: cannot remove `hello': Is a directory
hbae003@hammer.cs.ucr.edu$ rm -r hello
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ rcho
exec: No such file or directory
hbae003@hammer.cs.ucr.edu$ rm nothing
rm: cannot remove `nothing': No such file or directory
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ echo this should out
this should out
hbae003@hammer.cs.ucr.edu$ eyyy
exec: No such file or directory
hbae003@hammer.cs.ucr.edu$ vim status
hbae003@hammer.cs.ucr.edu$ echo whoops										       ~												~												 ~												  ~												   ~												    ~												     ~												      ~												       ~												~												 ~												  ~												   ~												    ~												     ~												      ~												       ~												~												 ~												  ~												   ~												    ~												     ~												      ~												       ~												~												 ~												  ~												   ~												    ~												     ~												      ~												       ~												~												 ~												  ~												   ~												    ~												     ~												      ~												       ~												~												 ~												  0,0-1All:q
whoops
hbae003@hammer.cs.ucr.edu$ git status
# On branch exec
# Changed but not updated:
#   (use "git add/rm <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   a.out
#	modified:   rshell.cpp
#	deleted:    ../tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	single_command.sh
no changes added to commit (use "git add" and/or "git commit -a")
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ kd
exec: No such file or directory
hbae003@hammer.cs.ucr.edu$ ls -dffs
4 .
hbae003@hammer.cs.ucr.edu$ ls -werwerwerr
ls: invalid line width: erwerwerr
hbae003@hammer.cs.ucr.edu$ touch test
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh  test
hbae003@hammer.cs.ucr.edu$ rm test
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$		     l		      s
exec: No such file or directory
hbae003@hammer.cs.ucr.edu$ touch -s
touch: invalid option -- 's'
Try `touch --help' for more information.
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ exit
hbae003@hammer.cs.ucr.edu$ exit
hbae003@hammer.cs.ucr.edu$ exit
hbae003@hammer.cs.ucr.edu$ ls
a.out  rshell.cpp  single_command.sh
hbae003@hammer.cs.ucr.edu$ exit
hbae003@hammer.cs.ucr.edu$ ^C
[hbae003@hammer src]$ exit
exit

Script done on Fri 06 Nov 2015 11:03:36 AM PST
