CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = star.o

star: star.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

star.o: star.cpp

.PHONY : clean
clean :
	rm star $(OBJ)
