mode-check: main.c
	gcc -O2 -Wall -Werror -Wpedantic main.c -o mode-check

.PHONY: clean install

clean:
	rm -v mode-check

install: mode-check
	install -vDm 700 ./mode-check ~/.local/bin/mode-check
