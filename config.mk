# dogma version
VERSION = 0.1
# Customize below to fit your system

# paths
PREFIX = /usr/local
#MANPREFIX = $(PREFIX)/share/man

# flags
#CPPFLAGS = -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700
#CFLAGS = $(CPPFLAGS) -g -std=c17 -pedantic -Wall -O0
#LDFLAGS = $(LIBS) $(LDFLAGS)
CPPFLAGS = -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_FORTIFY_SOURCE=2
CFLAGS = $(CPPFLAGS) -O3

# compiler and linker
CC = gcc