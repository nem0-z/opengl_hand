hand:
	g++ -o hand -I/usr/include/GL *.cpp -lGL -lGLU -lglut

.PHONY:
	clean

clean:
	rm -rf *.o hand