CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = system.o

system: system.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

system.o: system.cpp planet.hpp

.PHONY : clean
clean :
	rm system $(OBJ)
