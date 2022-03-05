test: test.cpp
	g++ test.cpp -std=c++17 -g3 -Wall -pedantic -o test -fsanitize=address