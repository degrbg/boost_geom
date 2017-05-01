CC=clang++
OPT=-std=c++11 -O0

all: main.cpp
	$(CC) $(OPT) main.cpp
