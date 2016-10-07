# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = myprog

all:
	cd core && make all
	cd effects && make all
	cd filters && make all
	cd oscillators && make all

clean:
	cd core && make clean
	cd effects && make clean
	cd filters && make clean
	cd oscillators && make clean