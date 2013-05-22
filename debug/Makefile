CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := debug.o
TESTBIN:= test.bin

.PHONY: all clean test

all: $(DEPS)

test: $(DEPS)
	$(CC) $(CFLAGS) -I. -o $(TESTBIN) test/test.c debug.o
	./$(TESTBIN)

debug.o: debug.c debug.h
	$(CC) $(CFLAGS) -c -o debug.o debug.c

clean:
	rm -rfv *.o
	$(TESTBIN)

clang:
	$(MAKE) CC=clang
