link: Matrix.o p1.o
	g++ -o p1 p1.o Matrix.o

Matrix.o: Matrix.h Matrix.cpp 
	g++ -c -Wall -std=c++14 -g -pedantic-errors Matrix.cpp

p1.o: p1.cpp Matrix.cpp Matrix.h
	g++ -c -Wall -std=c++14 -g -pedantic-errors p1.cpp

clean:
	/bin/rm P1 *.o