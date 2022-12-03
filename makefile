all: test
	./test

%: %.cpp
	g++ $< -std=c++17 -g3 -Wall -pedantic -o $@ -fsanitize=address -DLOCAL -O0

gcc:
	g++-12 test.cpp -std=c++17 -g3 -Wall -pedantic -o test #-fsanitize=address