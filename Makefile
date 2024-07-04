CC := LANG=C gcc
CFLAGS := -O2 -Wall -fstack-protector
LDFLAGS := -shared -fPIC
SOURCES := $(filter-out test.c, $(wildcard *.c))

# if PREFIX is not set by the enviroment
ifeq ($(PREFIX),)
	PREFIX := /usr
endif
LIBRARY_PATH := $(PREFIX)/lib/
INCLUDE_PATH := $(PREFIX)/include/

build:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(CURDIR)/libzarg.so $(SOURCES)

install:
	install -d $(LIBRARY_PATH)
	install -m 644 $(CURDIR)/libzarg.so $(LIBRARY_PATH)
	install -d $(INCLUDE_PATH)
	install -m 644 $(CURDIR)/zarg.h $(INCLUDE_PATH)
	ldconfig

test:
	$(CC) $(CFLAGS) -lzarg -o $(CURDIR)/test $(CURDIR)/test.c
	$(CURDIR)/test

uninstall:
	rm $(LIBRARY_PATH)libzarg.so
	rm $(INCLUDE_PATH)zarg.h
	ldconfig

clean: uninstall
	rm $(CURDIR)/libzarg.so
	rm $(CURDIR)/test
