CC := LANG=C gcc
CFLAGS := -O2 -Wall -fstack-protector
LDFLAGS := -fPIC -lzarg
SOURCES := $(wildcard *.c)

build:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(CURDIR)/base $(SOURCES)
