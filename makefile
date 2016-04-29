Lab07: main.o Test.o
	g++ -g -Wall -std=c++11 main.o Test.o -o Lab07

main.o: main.cpp Test.cpp
	g++ -g -Wall -std=c++11 -c main.cpp 

Test.o: Test.cpp LinkedList.hpp LinkedList.h Node.hpp Node.h
	g++ -g -Wall -std=c++11 -c Test.cpp