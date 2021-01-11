TestStap: tests/TestStap.cc
	g++ $^ -O0 -o build/$@ -ggdb -gdwarf

TestStapC: tests/TestStap.c
	gcc $^ -O0 -o build/$@ -ggdb -gdwarf

thirdparties:
	make -C cppcraft all
