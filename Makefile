all:
	cc src/*.c src/entity/*.c src/util/*.c src/component/*.c src/world/*.c -o build/Game -lraylib
	./build/Game
compile:
	cc src/*.c src/entity/*.c src/util/*.c src/component/*.c src/world/*.c -o build/Game -lraylib
run:
	./build/Game
