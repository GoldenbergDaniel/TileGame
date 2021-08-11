run:
	./build/Speedrun
compile:
	cmake --build ./build
test:
	cmake --build ./build
	./build/Speedrun
