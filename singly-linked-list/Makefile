CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := linked-list.o
TESTBIN:= test.bin

.PHONY: all clean test valgrind

all: $(DEPS)

$(TESTBIN): $(DEPS)
	$(CC) $(CFLAGS) -I. -o $(TESTBIN) test/test.c $(DEPS)

test: $(TESTBIN)
	/usr/bin/time ./$(TESTBIN)

valgrind: test
	valgrind --leak-check=full ./$(TESTBIN)

linked-list.o: linked-list.c linked-list.h
	$(CC) $(CFLAGS) -c -o linked-list.o linked-list.c

clean:
	rm -rfv *.o
	rm -rfv $(TESTBIN)

clang:
	$(MAKE) CC=clang
