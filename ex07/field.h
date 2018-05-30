# ifndef FIELD_H
# define FIELD_H

# include "defs.h"
# include "snake.h"

class Field {
private:
    int width, height, **matrix;
    Snake *snake;

public:
    Field();
    int* operator [](int idx);
    void spawnSnake();
    void refresh(Direction direction);
    void spawnFood();
    void reset();
    int getWidth();
    int getHeight();
    ~Field();
};

# endif /* end of include guard: FIELD_H */
