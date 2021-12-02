test: test.o
	g++ test.o -o test
	rm test.o

test.o:
	g++ test.cpp -std=c++17 -Wall -pedantic -c