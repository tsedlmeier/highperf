CFLAGS= -O3 -Wextra -Wall

.PHONY: all

all: master worker

run: 
	time ./master | parallel ./worker

master: src/master_rec.c
	gcc $(CFLAGS) $< -o $@

worker: src/worker_rec.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -rf master worker
