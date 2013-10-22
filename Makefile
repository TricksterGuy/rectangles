CFLAGS := -std=c++0x -Wall -Werror -pedantic -O2

all : Rectangles

main.o : main.cpp Region.hpp Rectangle.hpp
	g++ -c $(CFLAGS) main.cpp

Region.o : Region.cpp Rectangle.hpp Region.hpp
	g++ -c $(CFLAGS) Region.cpp

Rectangle.o : Rectangle.cpp Rectangle.hpp
	g++ -c $(CFLAGS) Rectangle.cpp

RectangleSet.o : RectangleSet.cpp RectangleSet.hpp Rectangle.hpp Region.hpp
	g++ -c $(CFLAGS) RectangleSet.cpp

Rectangles : main.o Region.o Rectangle.o
	g++ -o Rectangles main.o Region.o Rectangle.o RectangleSet.o -lsfml-graphics -lsfml-system -lsfml-window -L/usr/local/lib -I/usr/local/include

clean :
	rm -f Rectangles *.o
