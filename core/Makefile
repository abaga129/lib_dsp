# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

WNO = -Wno-reorder

# file names
BZC = BezierCurve
BFF = Buffer
ENV = EnvelopeDetector
FNC = dsp_functions

all:
	$(CC) $(CFLAGS) -c $(BZC).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(BFF).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(ENV).cpp $(WNO)
	ld -r $(BZC).o $(BFF).o $(ENV).o -o core.o
	mv core.o ../include/core.o

clean:
	$(RM) $(BZC).o $(BFF).o $(ENV).o