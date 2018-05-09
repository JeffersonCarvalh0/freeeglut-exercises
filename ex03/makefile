CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = board.o

board: board.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

board.o: board.cpp

.PHONY : clean
clean :
	rm board $(OBJ)
