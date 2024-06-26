# <your name> and <your JHED>
# __Add your name and JHED above__
# Midterm Project - Solution Makefile

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra
OBJS=checkerboard.o ppm_io.o img_process.o 
## TODO: Write your own Makefile commands to link and compile your project as well as the cleanup


## Below are commands to link and compile the checkerboard program
# Links together files needed to create the checkerboard executable
checkerboard : $(OBJS)
	$(CC) -o $@ $(OBJS)

# Compile the ppm i/o source code
ppm_io.o: ppm_io.c ppm_io.h
	$(CC) $(CFLAGS) -c ppm_io.c

img_process: img_process.c img_process.h
	$(CC) $(CFLAGS) -c img_process.c

# Removes all object files and the executable named project, so we can start fresh
clean:
	rm -f *.o checkerboard
