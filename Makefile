#
# Files
#

SOURCES := $(wildcard *.c)

BUILDDIR := build
EXECUTABLE := libzarg.so

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

LDFLAGS := -shared -fPIC

#
# Targets not producing output files
#

.PHONY: format clean install uninstall

#
# Build
#

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(BUILDDIR) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)


install: $(BUILDDIR)/$(EXECUTABLE)
	install -d $(LIBRARY_PATH)
	install -m 644 $^ $(LIBRARY_PATH)
	install -d $(INCLUDE_PATH)
	install -m 644 zarg.h $(INCLUDE_PATH)
	ldconfig

uninstall:
	rm $(LIBRARY_PATH)$(EXECUTABLE)
	rm $(INCLUDE_PATH)zarg.h
	ldconfig

#
# Utilities
#

format:
	indent $(SOURCES) $(wildcard *.h) -linux -nut -i4

run: $(BUILDDIR)/$(EXECUTABLE)
	./$^

clean: $(BUILDDIR)
	rm -r $^
