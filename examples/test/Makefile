# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all:
	$(CC) $(CFLAGS) ../../include/lib_dsp.o test.cpp -o test.out
	chmod +x test.out

clean:
	rm -rf test.out