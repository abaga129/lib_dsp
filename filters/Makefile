# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = myprog

# file names
BQF = BiQuadFilter
LPI = LowPassIIR
HPI = HighPassIIR
BPI = BandPassIIR
PI = PeakIIR

all:
	$(CC) $(CFLAGS) -c $(BQF).cpp
	$(CC) $(CFLAGS) -c $(LPI).cpp
	$(CC) $(CFLAGS) -c $(HPI).cpp
	$(CC) $(CFLAGS) -c $(BPI).cpp
	$(CC) $(CFLAGS) -c $(PI).cpp


$(BQF).o: $(BQF).h $(BQF).cpp
	$(CC) $(CFLAGS) -c $(BQF).cpp
	
$(LPI).o: $(LPI).h $(LPI).cpp
	$(CC) $(CFLAGS) -c $(LPI).cpp
    
$(HPI).o: $(HPI).h $(HPI).cpp
	$(CC) $(CFLAGS) -c $(HPI).cpp

$(BPI).o: $(BPI).h $(BPI).cpp
	$(CC) $(CFLAGS) -c $(BPI).cpp

$(PI).o: $(PI).h $(PI).cpp
	$(CC) $(CFLAGS) -c $(PI).cpp

clean:
	$(RM) $(BQF).o $(LPI).o $(HPI).o $(BPI).o $(PI).o
