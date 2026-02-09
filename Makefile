PREFIX ?= /usr/local
CC ?= gcc

CFLAGS  ?= -O2 -Wall -Werror -Wpedantic
LDFLAGS ?=
LDLIBS  ?=

ifeq ($(STATIC),1)
  LDFLAGS += -static
endif

mode-check: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

.PHONY: clean install-user install-system

clean:
	rm -vf mode-check

install-user: mode-check
	install -vDm 700 ./mode-check ~/.local/bin/mode-check

install-system: mode-check
	install -vDm 755 ./mode-check $(PREFIX)/bin/mode-check