CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = name.o

name: name.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

name.o: name.cpp

.PHONY : clean
clean :
	rm name $(OBJ)
