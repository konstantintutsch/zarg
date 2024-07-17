CC := LANG=C gcc
CFLAGS := -O2 -Wall -fstack-protector
LDFLAGS := -shared -fPIC
SOURCES := $(wildcard *.c)

# if PREFIX is not set by the enviroment
ifeq ($(PREFIX),)
	PREFIX := /usr
endif
LIBRARY_PATH := $(PREFIX)/lib/
INCLUDE_PATH := $(PREFIX)/include/

format:
	indent $(SOURCES) $(wildcard *.h) -linux -nut -i4

build:
	$(CC) $(CFLAGS) -o $(CURDIR)/libzarg.so $(SOURCES) $(LDFLAGS)

install:
	install -d $(LIBRARY_PATH)
	install -m 644 $(CURDIR)/libzarg.so $(LIBRARY_PATH)
	install -d $(INCLUDE_PATH)
	install -m 644 $(CURDIR)/zarg.h $(INCLUDE_PATH)
	ldconfig

uninstall:
	rm $(LIBRARY_PATH)libzarg.so
	rm $(INCLUDE_PATH)zarg.h
	ldconfig

clean: uninstall
	rm $(CURDIR)/libzarg.so
