CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := linked-list.o
TESTBIN:= test.bin

.PHONY: all clean test

all: $(DEPS)

test: $(DEPS)
	$(CC) $(CFLAGS) -I. -o $(TESTBIN) test/test.c linked-list.o
	./$(TESTBIN)

linked-list.o: linked-list.c linked-list.h
	$(CC) $(CFLAGS) -c -o linked-list.o linked-list.c

clean:
	rm -rfv *.o
	rm -rfv $(TESTBIN)

clang:
	$(MAKE) CC=clang
