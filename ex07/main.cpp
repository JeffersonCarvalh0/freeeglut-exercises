# include "defs.h"
# include "snake.h"
# include "field.h"
# include <GL/glut.h>
# include <iostream>

Field field;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
}

void drawSquare(int x, int y, int size, float *color) {
    glBegin(GL_POLYGON);
        glColor3f(color[0], color[1], color[2]);
        glVertex2i(x, y);
        glVertex2i(x, y + size);
        glVertex2i(x + size, y + size);
        glVertex2i(x + size, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float cyan[3] = { 0.0, 1.0, 1.0 };
    float dark_cyan[3] = { 0.0, 0.7, 0.7 };
    float red[3] = { 1.0, 0.0, 0.0 };

    for (int i = 0; i < field.getHeight(); ++i) {
        for (int j = 0; j < field.getWidth(); ++j) {
            float *cur_color;
            switch (field[i][j]) {
                case -1: cur_color = red; break;
                case 1: cur_color = cyan; break;
                case 2: cur_color = dark_cyan; break;
            }
            if (field[i][j] == -1 || field[i][j] == 1 || field[i][j] == 2)
                drawSquare(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, cur_color);
        }
    }
    glFlush();
}

bool started = false;
int start = 0;
Direction direction = RIGHT;

void animate() {
    if (field.reseted) return;

    int end = glutGet(GLUT_ELAPSED_TIME);
    if (end - start >= SPEED) {
        field.refresh(direction);
        start = glutGet(GLUT_ELAPSED_TIME);
        glutPostRedisplay();
    }
}

void keyPressed(unsigned char key, int x, int y) {
    if (field.reseted) field.reseted = false;
    switch (key) {
        case 'w': direction = UP; break;
        case 'a': direction = LEFT; break;
        case 's': direction = DOWN; break;
        case 'd': direction = RIGHT; break;
        case 'r': field.reset(); glutPostRedisplay(); break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    init();
    glutIdleFunc(animate);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
