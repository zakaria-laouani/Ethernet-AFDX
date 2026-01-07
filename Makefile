CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude

all: sender receiver

sender: src/sender.c src/afdx_trame.c
	$(CC) $(CFLAGS) $^ -o $@

receiver: src/receiver.c src/afdx_trame.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f sender receiver

.PHONY: all clean
