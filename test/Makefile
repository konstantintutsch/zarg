CC := LANG=C gcc
CFLAGS := -O2 -Wall -fstack-protector
LDFLAGS := -lzarg
SOURCES := $(wildcard *.c)

build:
	$(CC) $(CFLAGS) -o $(CURDIR)/base $(SOURCES) $(LDFLAGS)
