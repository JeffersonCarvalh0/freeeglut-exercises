CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = system.o planet.o

system: system.o planet.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

system.o: system.cpp

planet.o: planet.cpp

.PHONY : clean
clean :
	rm system $(OBJ)
