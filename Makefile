CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = linkedlist.o stacksPractice.o

stacksPractice: $(OBJECTS)
	 $(CXX) -g $(CXXFLAGS) -o stacksPractice linkedlist.o stacksPractice.o

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CXX) -g $(CXXFLAGS) -c linkedlist.cpp
	
stacksPractice.o: linkedlist.cpp linkedlist.h stacksPractice.cpp
	$(CXX) -g $(CXXFLAGS) -c stacksPractice.cpp

clean: 
	rm -f *.o
	rm stacksPractice