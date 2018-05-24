CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = move.o

move: move.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

move.o: move.cpp

.PHONY : clean
clean :
	rm move $(OBJ)
