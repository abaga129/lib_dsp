# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# file names
BC = BezierCurve
BF = buffer
FNC = dsp_functions

all:
	$(RM) $(BC).o $(BF).o $(FNC).o
	$(CC) $(CFLAGS) -c $(BC).cpp
	$(CC) $(CFLAGS) -c $(BF).cpp
	$(CC) $(CFLAGS) -c $(FNC).cpp


$(BC).o: $(BC).h $(BC).cpp
	$(CC) $(CFLAGS) -c $(BC).cpp
	
$(BF).o: $(BF).h $(BF).cpp
	$(CC) $(CFLAGS) -c $(BF).cpp

$(FNC).o: $(FNC).h $(FNC).cpp
	$(CC) $(CFLAGS) -c $(FNC).cpp

clean:
	$(RM) $(BC).o $(BF).o $(FNC).o