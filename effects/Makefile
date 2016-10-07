# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# file names
CMP = Compressor
DDL = DigitalDelay

all:
	$(CC) $(CFLAGS) -c $(CMP).cpp
	$(CC) $(CFLAGS) -c $(DDL).cpp

$(CMP).o: $(CMP).h $(CMP).cpp
	$(CC) $(CFLAGS) -c $(CMP).cpp
	
$(DDL).o: $(DDL).h $(DDL).cpp
	$(CC) $(CFLAGS) -c $(DDL).cpp

clean:
	$(RM) $(CMP).o $(DDL).o