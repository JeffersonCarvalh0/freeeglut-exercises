CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = tetris.o

tetris: tetris.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

tetris.o: tetris.cpp

.PHONY : clean
clean :
	rm tetris $(OBJ)
