# include "utils.h"
# include "snake.h"
# include "field.h"
# include <GL/glut.h>
# include <iostream>

Direction new_direction = RIGHT;
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
    float red[3] = { 1.0, 0.0, 0.0 };

    for (int i = 0; i < field.getHeight(); ++i) {
        for (int j = 0; j < field.getWidth(); ++j) {
            if (field[i][j] == -1) drawSquare(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, red);
            else if (field[i][j] != 0) drawSquare(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, cyan);
        }
    }

    field.refresh(new_direction);
    glFlush();
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': new_direction = UP; break;
        case 'a': new_direction = LEFT; break;
        case 's': new_direction = DOWN; break;
        case 'd': new_direction = RIGHT; break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
