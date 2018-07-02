CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = 3dboard.o

3dboard: 3dboard.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

3dboard.o: 3dboard.cpp

.PHONY : clean
clean :
	rm 3dboard $(OBJ)
