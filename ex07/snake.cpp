# include "snake.h"
# include <iostream>

using namespace std;

SnakeSquare::SnakeSquare(int x, int y, Direction direction):
x(x), y(y), direction(direction) {
    cout << "New snake square created at " << x << ' ' << y << '\n';
}

Snake::Snake(int field_width, int field_height, int initial_size):
field_width(field_width), field_height(field_height) {
    for (int i = 0; i < initial_size; ++i)
        body.push_back(SnakeSquare(i, 0, RIGHT));
    cout << "New snake created.\n";
}

const list<SnakeSquare>& Snake::getBody() { return body; }

void Snake::grow() {
    SnakeSquare tail = body.front();
    SnakeSquare new_tail(tail.x, tail.y, tail.direction);
    switch(tail.direction) {
        case UP: new_tail.y = (new_tail.y - 1) % field_height; break;
        case DOWN: new_tail.y = (new_tail.y + 1) % field_height; break;
        case LEFT: new_tail.x = (new_tail.x + 1) % field_width; break;
        case RIGHT: new_tail.x = (new_tail.x - 1) % field_width; break;
    }
    body.push_front(new_tail);
    cout << "Snake grew to size " << body.size() << '\n';
}

bool Snake::move(Direction new_direction) {
    SnakeSquare head = body.back();
    SnakeSquare new_head(head.x, head.y, new_direction);
    switch(new_direction) {
        case UP: if (head.direction == DOWN) return false; new_head.y = (new_head.y + 1) % field_height; break;
        case DOWN: if (head.direction == UP) return false; if (--new_head.y < 0) new_head.y += field_height;  break;
        case LEFT: if (head.direction == RIGHT) return false; if (--new_head.x < 0) new_head.x += field_width; break;
        case RIGHT: if (head.direction == LEFT) return false; new_head.x = (new_head.x + 1) % field_width; break;
    }
    body.push_back(new_head);
    body.pop_front();
    for (auto it = body.begin(); next(it) != body.end(); ++it) it->direction = next(it)->direction;
    cout << "Snake moved to " << new_head.x << ' ' << new_head.y << '\n';
    return true;
}
