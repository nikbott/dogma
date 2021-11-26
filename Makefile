# See COPYING file for license details.
.POSIX:

include config.mk

SRC = dogma.c fasta.c sequence.c transcription.c
OBJ = $(SRC:.c=.o)

all: options dogma

options:
	@echo dogma build options:
	@echo "CFLAGS  = $(CFLAGS)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "CC      = $(CC)"

.c.o:
	$(CC) $(CFLAGS) -c $<

dogma.o: dogma.h

$(OBJ): config.mk

dogma: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f dogma $(OBJ) dogma-$(VERSION).tar.gz

dist: clean
	mkdir -p dogma-$(VERSION)
	cp -R COPYING Makefile README.md config.mk\
		dogma.h $(SRC)\
		dogma-$(VERSION)
	tar -cf - dogma-$(VERSION) | gzip > dogma-$(VERSION).tar.gz
	rm -rf dogma-$(VERSION)

install: dogma
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f dogma $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dogma

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dogma

.PHONY: all options clean dist install uninstall