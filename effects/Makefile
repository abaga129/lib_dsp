# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

WNO = -Wno-reorder

# file names
CMP = Compressor
DDL = DigitalDelay
MDL = ModulatedDelay
FLG = Flanger
CHR = Chorus
VBR = Vibrato

all:
	$(CC) $(CFLAGS) -c $(CMP).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(DDL).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(MDL).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(FLG).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(CHR).cpp $(WNO)
	$(CC) $(CFLAGS) -c $(VBR).cpp $(WNO)
	ld -r $(CMP).o $(DDL).o $(MDL).o $(FLG).o $(CHR).o $(VBR).o -o effects.o
	mv effects.o ../include/effects.o

$(CMP).o: $(CMP).h $(CMP).cpp
	$(CC) $(CFLAGS) -c $(CMP).cpp
	
$(DDL).o: $(DDL).h $(DDL).cpp
	$(CC) $(CFLAGS) -c $(DDL).cpp

$(MDL).o: $(MDL).h $(MDL).cpp
	$(CC) $(CFLAGS) -c $(MDL).cpp

clean:
	$(RM) $(CMP).o $(DDL).o $(MDL).o $(FLG).o $(CHR).o $(VBR).o