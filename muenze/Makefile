CFLAGS= -O3 -Wextra -Wall

.PHONY: all

all: muenze muenze2 debug

run: 
	./muenze

muenze: src/muenze.c
	gcc $(CFLAGS) $< -o $@

muenze2: src/muenze2.c
	gcc $(CFLAGS) $< -o $@

debug: src/muenze2.c
	gcc -g $< -o $@

clean:
	rm -rf muenze muenze2
