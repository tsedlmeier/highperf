CFLAGS= -O3 -Wextra -Wall

.PHONY: all

all: muenze muenze2

run: 
	./muenze

muenze: src/muenze.c
	gcc $(CFLAGS) $< -o $@

muenze2: src/muenze2.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -rf muenze muenze2
