run:
	cmake -S . -B build
	cmake --build build
	./build/server