# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

WNO = -Wno-reorder

# file names
LD = lib_dsp
COR = core
EFX = effects
FTR = filters
OSC = oscillators


all:
	ld -r $(COR).o $(EFX).o $(FTR).o $(OSC).o -o $(LD).o

clean:
	$(RM) $(FX).o $(COR).o $(OSC).o $(FTR).o $(EFX).o $(LD).o