#2 useful commands for makefile
#make all (compiles all files into executable)
#make clean (removes all object files)
CC = g++ -lpthread
CFLAGS = -c -std=c++11 -O2
LDFLAGS =
SOURCES = main.cpp buffer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	/bin/rm -f *.o all
