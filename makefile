CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11
OBJ = main.o

main: main.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

main.o: main.cpp

.PHONY : clean
clean :
	rm main $(OBJ)
