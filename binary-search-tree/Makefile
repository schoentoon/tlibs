CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := binary-search-tree.o
TESTBIN:= test.bin

.PHONY: all clean test valgrind

all: $(DEPS)

$(TESTBIN): $(DEPS)
	$(CC) $(CFLAGS) -I. -o $(TESTBIN) test/test.c $(DEPS)

test: $(TESTBIN)
	time ./$(TESTBIN)

valgrind: test
	valgrind --leak-check=full ./$(TESTBIN)

binary-search-tree.o: binary-search-tree.c binary-search-tree.h
	$(CC) $(CFLAGS) -c -o binary-search-tree.o binary-search-tree.c

clean:
	rm -rfv *.o
	rm -rfv $(TESTBIN)

clang:
	$(MAKE) CC=clang
