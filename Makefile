CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized


OBJECTS = storage.o hashtable.o node.o start.o

main: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

storage.o = storage.hpp storage.cpp

hashtable.o = hashtable.hpp hashtable.cpp

node.o = node.hpp node.cpp

start.o = start.hpp start.cpp



.PHONY : clean
clean:
	rm -rf *.o
