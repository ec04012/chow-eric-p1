matrix: 
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors Matrix.cpp

p1:
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors P1.cpp

link: Matrix.o, P1.o
	g++ P1 P1.o Matrix.o

clean:
	/bin/rm P1 *.o