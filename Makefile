run:
	./build/TileGame
compile:
	cmake --build ./build
test:
	cmake --build ./build
	./build/TileGame
