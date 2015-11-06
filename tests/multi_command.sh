Script started on Fri 06 Nov 2015 01:47:10 PM PST
[hbae003@hammer src]$ ./a.out
hbae003@hammer.cs.ucr.edu$ ls -a; mkdir test || echo no && echo no2
ls -a
.  ..  a.out  multi_command.sh	rshell.cpp  .rshell.cpp.swp
mkdir test
hbae003@hammer.cs.ucr.edu$ ls;-touch text.txt && touch help.txt || echo no
ls
a.out  multi_command.sh	 rshell.cpp  test
touch text.txt
touch help.txt
hbae003@hammer.cs.ucr.edu$ ls -a || ls || ls || echo no
ls -a
.  ..  a.out  help.txt	multi_command.sh  rshell.cpp  .rshell.cpp.swp  test  text.txt
ls
a.out  help.txt	 multi_command.sh  rshell.cpp  test  text.txt
hbae003@hammer.cs.ucr.edu$ ls || ls || ls || ls || ls || ls
ls
a.out  help.txt	 multi_command.sh  rshell.cpp  test  text.txt
ls
a.out  help.txt	 multi_command.sh  rshell.cpp  test  text.txt
ls
a.out  help.txt	 multi_command.sh  rshell.cpp  test  text.txt
hbae003@hammer.cs.ucr.edu$ exit
[hbae003@hammer src]$ ls || ls || ls||| ls || ls || ls
a.out  help.txt	 multi_command.sh  rshell.cpp  test  text.txt
./a.out3@hammer src]$ ls || ls || ls || ls || ls || ls
hbae003@hammer.cs.ucr.edu$ ls -a; mkdir test2 && rm--r test || ls; ls -a
ls -a
.  ..  a.out  help.txt	multi_command.sh  rshell.cpp  .rshell.cpp.swp  test  text.txt
mkdir test2
rm -r test
ls -a
.  ..  a.out  help.txt	multi_command.sh  rshell.cpp  .rshell.cpp.swp  test2  text.txt
hbae003@hammer.cs.ucr.edu$ rm -r test2 && rm test2 &&&&&&&
rm -r test2
rm test2 &&&&&&&
rm: cannot remove `test2': No such file or directory
rm: cannot remove `&&&&&&&': No such file or directory
hbae003@hammer.cs.ucr.edu$ ls
ls
a.out  help.txt	 multi_command.sh  rshell.cpp  text.txt
hbae003@hammer.cs.ucr.edu$ rm text.txt
rm text.txt
hbae003@hammer.cs.ucr.edu$ ls
ls
a.out  help.txt	 multi_command.sh  rshell.cpp
hbae003@hammer.cs.ucr.edu$ echo hey; ; rm help.txt && && && && || &&
echo hey
hey

rm help.txt




hbae003@hammer.cs.ucr.edu$ ls
ls
a.out  multi_command.sh	 rshell.cpp
hbae003@hammer.cs.ucr.edu$ git status && mkdir test; ls || echo no; rm -r test
git status
# On branch exec
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   a.out
#	modified:   rshell.cpp
#	modified:   ../tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	.rshell.cpp.swp
#	multi_command.sh
no changes added to commit (use "git add" and/or "git commit -a")
mkdir test
ls
a.out  multi_command.sh	 rshell.cpp  test
rm -r test
hbae003@hammer.cs.ucr.edu$ ls
ls
a.out  multi_command.sh	 rshell.cpp
hbae003@hammer.cs.ucr.edu$ exit
[hbae003@hammer src]$ exit
exit

Script done on Fri 06 Nov 2015 01:52:52 PM PST
