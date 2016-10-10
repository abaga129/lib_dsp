# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

WNO = -Wno-reorder

# file names
CR = core
FX = effects
OSC = oscillators
LBD = lib_dsp
FLT = filters


all:
	ld -r core.o effects.o filters.o oscillators.o -o lib_dsp.o

clean:
	$(RM) $(FX).o $(CR).o $(OSC).o $(FLT).o $(LBD).o lib_dsp.o