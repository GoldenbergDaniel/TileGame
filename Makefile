run:
	./build/Speedrun
compile:
	cmake --build ./build
test:
	cmake --build ./build_debug
	./build_debug/Speedrun
