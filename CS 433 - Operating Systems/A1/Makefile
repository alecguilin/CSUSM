###################################
# OS COURSE - 2006
# 
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = myTest222			# target executable (output)
SRC = main.cpp PCB.cpp RQ.cpp      # .c or .cpp source files.
OBJ = $(SRC:.cpp=.o) 	# object files for the target. Add more to this and next lines if there are more than one source files.

all : main.o PCB.o RQ.o
	g++ main.o PCB.o RQ.o -o run

main.o: main.cpp
	g++ -c main.cpp

PCB.o: PCB.cpp PCB.h
	g++ -c PCB.cpp

RQ.o: RQ.cpp RQ.h
	g++ -c RQ.cpp

# cleanup
clean:
	/bin/rm -f *.o all

# DO NOT DELETE