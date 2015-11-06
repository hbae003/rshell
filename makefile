GCC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
FILEPATH = ./src/rshell.cpp
OUTFILE = bin/rshell

all: rshell

rshell:
	if [ ! -d bin ]; then mkdir bin; fi
	$(GCC) $(CFLAGS) $(FILEPATH) \
	-o $(OUTFILE)
