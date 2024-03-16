all: test
	./test

%: %.cpp
	clang++ $< -std=c++20 -g3 -o $@ -DLOCAL -O0 -Wall -pedantic -fdiagnostics-color=always -fsanitize=address -fsanitize=undefined 

nd:
	clang++ test.cpp -std=c++20 -pedantic -O2 -o test
	./test

l:
	clang++ test.cpp -std=c++20 -pedantic -g3 -O0 -o test
	./test

gcc:
	g++-13 test.cpp -std=c++20 -g3 -Wall -pedantic -o test #-fsanitize=address -DLOCAL 
	./test

c:
	clang test.c -g3 -Wall -pedantic -o testc -fsanitize=address -DLOCAL -O0 -fsanitize=undefined
	./testc