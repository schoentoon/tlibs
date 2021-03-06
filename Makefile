CFLAGS := $(CFLAGS) -Wall -O2 -mtune=native -g
CC     := gcc
DEPS   := debug singly-linked-list binary-search-tree

.PHONY: all clean test

all:
	$(foreach dir,$(DEPS),$(MAKE) -C $(dir);)

test:
	$(foreach dir,$(DEPS),$(MAKE) -C $(dir) test;)

clean:
	$(foreach dir,$(DEPS),$(MAKE) -C $(dir) clean;)

clang:
	$(MAKE) CC=clang
