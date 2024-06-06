make:
	g++ -o main ./src/main.cpp
	./main > image.ppm
	feh image.ppm

com:
	g++ -o main ./src/main.cpp
	./main > image.ppm

view:
	feh image.ppm
