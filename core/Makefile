# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

WNO = -Wno-reorder

# file names
BC = BezierCurve
BF = Buffer
FNC = dsp_functions
ENV = EnvelopeDetector

all:
	$(CC) $(CFLAGS) -c $(BC).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(BF).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(FNC).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(ENV).cpp $(WNO)
	ld -r $(BC).o $(BF).o $(FNC).o $(ENV).o -o core.o
	mv core.o ../include/core.o


$(BC).o: $(BC).h $(BC).cpp
	$(CC) $(CFLAGS) -c $(BC).cpp
	
$(BF).o: $(BF).h $(BF).cpp
	$(CC) $(CFLAGS) -c $(BF).cpp

$(FNC).o: $(FNC).h $(FNC).cpp
	$(CC) $(CFLAGS) -c $(FNC).cpp

clean:
	$(RM) $(BC).o $(BF).o $(FNC).o