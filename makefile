CC=gcc
CFLAGS=-Wall -Werror

%::%.c %.h
	$(CC) $@.c -o $@ -Wall -Werror
