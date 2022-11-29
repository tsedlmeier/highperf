CFLAGS= -O3 -Wextra -Wall
LDFLAGS= -lm -lSDL2

.PHONY: all

all: mandelbrot_parallel mandelbrot debug mandelbrot_refactor

run: 
	./mandelbrot 

mandelbrot: src/mandelbrot.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

mandelbrot_refactor: src/mandelbrot_refactor.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

mandelbrot_parallel: src/mandelbrot_parallel.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

debug: src/mandelbrot_refactor.c
	gcc -std=c99 -g $(LDFLAGS) $< -o $@

clean:
	rm -rf mandelbrot
