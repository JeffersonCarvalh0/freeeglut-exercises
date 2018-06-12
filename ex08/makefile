CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = rotations.o

rotations: rotations.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

rotations.o: rotations.cpp

.PHONY : clean
clean :
	rm rotations $(OBJ)
