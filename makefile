all: test
	./test

%: %.cpp
	clang++ $< -std=c++17 -g3 -Wall -pedantic -o $@ -fsanitize=address -DLOCAL -O0

gcc:
	g++-12 test.cpp -std=c++20 -g3 -Wall -pedantic -o test #-fsanitize=address
	./test

c:
	clang test.c -g3 -Wall -pedantic -o test -fsanitize=address -DLOCAL -O0
	./test