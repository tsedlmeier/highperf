CFLAGS= -O3 -Wextra -Wall

.PHONY: all

all: muenze

run: 
	./muenze

muenze: src/muenze.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -rf muenze
