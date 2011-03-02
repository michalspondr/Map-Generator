CC=g++
CFLAGS=-g -DDEBUG

all: maze.cc map.o print.h map_patterns.o
	$(CC) $(CFLAGS) -o maze maze.cc map.o map_patterns.o

map.o: map.cc map.h
	$(CC) $(CFLAGS) -c map.cc

map_patterns.o: map_patterns.cc map_patterns.h map.o
	$(CC) $(CFLAGS) -c map_patterns.cc

clean:
	        rm -f *.o maze

