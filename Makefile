PREFIX ?= /usr/local

mode-check: main.c
	gcc -O2 -Wall -Werror -Wpedantic main.c -o mode-check

.PHONY: clean install-user install-system

clean:
	rm -v mode-check

install-user: mode-check
	install -vDm 700 ./mode-check ~/.local/bin/mode-check

install-system: mode-check
	install -vDm 755 ./mode-check $(PREFIX)/bin/mode-check