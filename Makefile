CC := LANG=C gcc
CFLAGS := -Wall -fstack-protector
LDFLAGS := -shared -fPIC
SRCS := $(filter-out test.c, $(wildcard *.c))

# if PREFIX is not set by the enviroment
ifeq ($(PREFIX),)
	PREFIX := /usr
endif
LIBRARY_PATH := $(PREFIX)/lib/
INCLUDE_PATH := $(PREFIX)/include/

build:
	$(CC) $(CFLAGS) $(LDFLAGS) -o libzarg.so $(SRCS)

clean: uninstall
	rm libzarg.so
	rm test

install: build
	install -d $(LIBRARY_PATH)
	install -m 644 libzarg.so $(LIBRARY_PATH)
	install -d $(INCLUDE_PATH)
	install -m 644 zarg.h $(INCLUDE_PATH)
	ldconfig

uninstall:
	rm $(LIBRARY_PATH)libzarg.so
	rm $(INCLUDE_PATH)zarg.h
	ldconfig

test: build
	$(CC) $(CFLAGS) -lzarg -o test test.c
