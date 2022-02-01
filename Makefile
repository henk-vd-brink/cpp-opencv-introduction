all: main

clean: main
	rm -fr bin/*
	
main:
	g++ -std=c++17 src/main.cpp -I /usr/local/include/opencv4/opencv2 -o bin/main