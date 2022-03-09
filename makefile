all: test
	./test

%: %.cpp
	g++ $< -std=c++17 -g3 -Wall -pedantic -o $@ -fsanitize=address