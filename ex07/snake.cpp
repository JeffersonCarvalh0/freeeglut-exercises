# include "snake.h"
# include <iostream>

using namespace std;

SnakeSquare::SnakeSquare(int x, int y, Direction direction):
x(x), y(x), direction(direction) { cout << "New snake square created at " << x << ' ' << y << '\n'; }

Snake::Snake(int field_width, int field_height, int initial_size):
field_width(field_width), field_height(field_height) {
    for (int i = 0; i < initial_size; ++i)
        body.push_back(SnakeSquare(field_height - 1, i, RIGHT));
    cout << "New snake created.\n";
}

const list<SnakeSquare>& Snake::getBody() { return body; }

void Snake::grow() {
    auto tail = body.rbegin();
    SnakeSquare new_tail(tail->x, tail->y, tail->direction);
    switch(tail->direction) {
        case UP: new_tail.y = (new_tail.y + 1) % field_height; break;
        case DOWN: new_tail.y = (new_tail.y - 1) % field_height; break;
        case LEFT: new_tail.x = (new_tail.x - 1) % field_width; break;
        case RIGHT: new_tail.x = (new_tail.x + 1) % field_width; break;
    }
    body.push_back(new_tail);
    cout << "Snake grew to size " << body.size() << '\n';
}

void Snake::move(Direction new_direction) {
    auto head = body.begin();
    SnakeSquare new_head(head->x, head->y, new_direction);
    switch(new_direction) {
        case UP: if (head->direction == DOWN) return; new_head.y = (new_head.y - 1) % field_height; break;
        case DOWN: if (head->direction == UP) return; new_head.y = (new_head.y + 1) % field_height; break;
        case LEFT: if (head->direction == RIGHT) return; new_head.x = (new_head.x + 1) % field_width; break;
        case RIGHT: if (head->direction == LEFT) return; new_head.x = (new_head.x - 1) % field_width; break;
    }
    body.push_front(new_head);
    body.pop_back();
    cout << "Snake moved to " << new_head.x << ' ' << new_head.y << '\n';
}
