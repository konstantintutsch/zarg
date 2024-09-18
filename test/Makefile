#
# Files
#

SOURCES := $(wildcard *.c)

BUILDDIR := ../build
EXECUTABLE := test

#
# Compilers
#

CC := gcc
CFLAGS := -O2 -Wall -fstack-protector

LDFLAGS := -fPIC -lzarg

#
# Targets not producing output files
#

.PHONY: format clean run

#
# Build
#

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(BUILDDIR) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)

#
# Utilities
#

format:
	indent $(SOURCES) $(wildcard *.h) -linux -nut -i4

run: $(BUILDDIR)/$(EXECUTABLE)
	./$^

clean: $(BUILDDIR)
	rm -r $^
