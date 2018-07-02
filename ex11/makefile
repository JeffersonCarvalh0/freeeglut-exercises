CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = rotation.o

rotation: rotation.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

rotation.o: rotation.cpp

.PHONY : clean
clean :
	rm rotation $(OBJ)
