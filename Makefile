#
# Files
#

BUILDDIR := build

SOURCES := $(wildcard *.c)
SHAREDOBJECT := libzarg.so

TESTSOURCES := $(wildcard test/*.c)
TEST := test

ifeq ($(PREFIX),) # $(PREFIX) is empty or unset
	PREFIX := /usr
endif
LIBRARY_PATH := $(PREFIX)/lib/
INCLUDE_PATH := $(PREFIX)/include/

#
# Compilers
#

CC := gcc
CFLAGS := -O2 -Wall -fstack-protector

LDFLAGS := -fPIC

#
# Targets not producing output files
#

.PHONY: format test clean install uninstall

#
# Build
#

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(SHAREDOBJECT): $(BUILDDIR) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS) -shared

$(BUILDDIR)/$(TEST): $(BUILDDIR) $(TESTSOURCES)
	$(CC) $(CFLAGS) -o $@ $(TESTSOURCES) $(LDFLAGS) -lzarg


install: $(BUILDDIR)/$(SHAREDOBJECT)
	install -d $(LIBRARY_PATH)
	install -m 644 $^ $(LIBRARY_PATH)
	install -d $(INCLUDE_PATH)
	install -m 644 zarg.h $(INCLUDE_PATH)
	ldconfig

uninstall:
	rm $(LIBRARY_PATH)$(SHAREDOBJECT)
	rm $(INCLUDE_PATH)zarg.h
	ldconfig

#
# Utilities
#

format:
	indent $(SOURCES) $(wildcard *.h) -linux -nut -i4

test: $(BUILDDIR)/$(TEST)
	./test/automated.sh $^

clean: $(BUILDDIR)
	rm -r $^
