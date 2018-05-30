CXX = g++
LDLIBS = -lGLU -lGL -lglut
CXXFLAGS = -std=c++11 -g
OBJ = main.o field.o snake.o

main: main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDLIBS)

main.o: main.cpp field.h snake.h defs.h
field.o: field.cpp field.h snake.h defs.h
snake.o: snake.cpp snake.h defs.h

.PHONY : clean
clean :
	rm main $(OBJ)
