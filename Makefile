all: image.png

shtuff: shtuff.c
	gcc shtuff.c -lm -o shtuff

image.ppm: shtuff
	./shtuff

image.png: image.ppm
	convert image.ppm image.png
