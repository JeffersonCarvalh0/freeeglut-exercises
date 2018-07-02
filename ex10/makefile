CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = table.o

table: table.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

table.o: table.cpp

.PHONY : clean
clean :
	rm table $(OBJ)
