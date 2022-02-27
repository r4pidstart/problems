test: test.cpp
	g++ test.cpp -std=c++17 -g3 -fsanitize=address -Wall -pedantic -o test