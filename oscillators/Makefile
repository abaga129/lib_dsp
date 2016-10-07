# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# file names
DFO = DirectFormOscillator
GSO = GordonSmithOscillator

all:
	$(CC) $(CFLAGS) -c $(DFO).cpp
	$(CC) $(CFLAGS) -c $(GSO).cpp

$(DFO).o: $(DFO).h $(DFO).cpp
	$(CC) $(CFLAGS) -c $(DFO).cpp

$(GSO).o: $(GSO).h $(GSO).cpp
	$(CC) $(CFLAGS) -c $(GSO).cpp

clean:
	$(RM) $(DFO).o $(GSO).o