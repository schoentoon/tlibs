CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := debug.o
TESTBIN:= test.bin

.PHONY: all clean test

all: $(DEPS)

$(TESTBIN): $(DEPS)
	$(CC) $(CFLAGS) -I. -o $(TESTBIN) test/test.c $(DEPS)

test: $(TESTBIN)
	./$(TESTBIN)

debug.o: debug.c debug.h
	$(CC) $(CFLAGS) -c -o debug.o debug.c

clean:
	rm -rfv *.o
	rm -rfv $(TESTBIN)

clang:
	$(MAKE) CC=clang
