export MAKEFLAGS += --no-print-directory

all: run

run:
	cmake -S . -B build
	cmake --build build
	./build/distributed-nodes