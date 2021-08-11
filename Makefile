run:
	./cmake-build-debug/Speedrun
compile:
	cmake --build cmake-build-debug/
test:
	cmake --build cmake-build-debug/
	./cmake-build-debug/Speedrun
