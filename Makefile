make:
	g++ -o main ./main.cpp
	./main > image.ppm
	feh image.ppm
	rm main

com:
	g++ -o main ./src/main.cpp
	./main > image.ppm

view:
	feh image.ppm
