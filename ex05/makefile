CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = house.o

house: house.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

house.o: house.cpp

.PHONY : clean
clean :
	rm house $(OBJ)
