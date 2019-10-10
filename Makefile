
.PHONY: all
all: bin/libmapgen.so

bin/libmapgen.so: src/main.os src/generated_tilemap.os
	g++ -o bin/libmapgen.so \
			-shared \
			src/main.os src/generated_tilemap.os \
			-Lgodot-cpp/bin -lgodot-cpp.linux.debug.64

src/main.os: src/main.cpp src/generated_tilemap.hpp
	g++ -fPIC \
			-o src/main.os \
			-c src/main.cpp \
			-g -O3 -std=c++14 \
			-Igodot-cpp/include/ -Igodot-cpp/include/core -Igodot-cpp/include/gen \
			-Igodot-cpp/godot_headers

src/generated_tilemap.os: src/generated_tilemap.cpp src/generated_tilemap.hpp
	g++ -fPIC \
			-o src/generated_tilemap.os \
			-c src/generated_tilemap.cpp \
			-g -O3 -std=c++14 \
			-Igodot-cpp/include/ -Igodot-cpp/include/core -Igodot-cpp/include/gen \
			-Igodot-cpp/godot_headers

