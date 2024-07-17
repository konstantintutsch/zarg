CC := LANG=C gcc
CFLAGS := -O2 -Wall -fstack-protector
LDFLAGS := -lzarg
SOURCES := main.c

format:
	indent $(SOURCES) -linux -nut -i4

build:
	$(CC) $(CFLAGS) -o $(CURDIR)/base $(SOURCES) $(LDFLAGS)
