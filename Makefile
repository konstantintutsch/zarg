CC = LANG=C gcc
CFLAGS=-Wall -fstack-protector

SRCS := $(filter-out test.c, $(wildcard *.c))

build:
	$(CC) $(CFLAGS) -shared -fPIC -o libzarg.so $(SRCS)

test:
	$(CC) $(CFLAGS) -lzarg -o test test.c

install: build
	mv libzarg.so /usr/lib/
	cp zarg.h /usr/include/
	ldconfig

uninstall:
	rm /usr/lib/libzarg.so
	rm /usr/include/zarg.h
	ldconfig
