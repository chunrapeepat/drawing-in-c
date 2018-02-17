circle: circle.c
	gcc circle.c -o circle.bin && rm -rf image.ppm && ./circle.bin && open image.ppm