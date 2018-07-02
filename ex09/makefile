CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = sphere.o

sphere: sphere.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

sphere.o: sphere.cpp

.PHONY : clean
clean :
	rm sphere $(OBJ)
