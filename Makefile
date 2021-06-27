hand:
	g++ -o hand -I/usr/include/GL main.cpp src/*.cpp -lGL -lGLU -lglut

.PHONY:
	clean

clean:
	rm -rf *.o hand