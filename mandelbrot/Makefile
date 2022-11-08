CFLAGS= -O3 -Wextra -Wall
LDFLAGS= -lm -lSDL2

.PHONY: all

all: mandelbrot debug

run: 
	./mandelbrot 

mandelbrot: src/mandelbrot.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

debug: src/mandelbrot.c
	gcc -std=c99 -g $(LDFLAGS) $< -o $@

clean:
	rm -rf mandelbrot
