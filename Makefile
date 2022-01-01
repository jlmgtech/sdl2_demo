.PHONY: test clean

test:
	make game
	./game

game: bin/main.o bin/graphics.o bin/time.o bin/net.o bin/events.o
	gcc -o $@ $^ -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net -I/mingw64/include/ -L/mingw64/lib

bin/main.o: main.c
	gcc -g -c -o $@ $^

bin/net.o: lib/net.c
	gcc -g -c -o $@ $^

bin/graphics.o: lib/graphics.c
	gcc -g -c -o $@ $^

bin/events.o: lib/events.c
	gcc -g -c -o $@ $^

bin/time.o: lib/time.c
	gcc -g -c -o $@ $^

# bin/audio/o
# bin/input.o

clean:
	rm -rf game
	rm -rf bin/*
