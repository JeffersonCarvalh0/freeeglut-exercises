# include <GL/glut.h>

# define WIDTH 256
# define HEIGHT 256

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

void horizontalLine(int size, int x, int y) {
    glBegin(GL_LINES);
        glVertex2i(x, y);
        glVertex2i(x + size, y);
    glEnd();
}

void verticalLine(int size, int x, int y) {
    glBegin(GL_LINES);
        glVertex2i(x, y);
        glVertex2i(x, y - size);
    glEnd();
}

void drawMyName(int size, int x, int y) {
    // Char J
    horizontalLine(size, x, y);
    verticalLine(size, x + (size / 2), y);
    horizontalLine(size / 2, x, y - size);

    // Char E
    x += size * 2; // Space between the letters
    verticalLine(size, x, y);
    horizontalLine(size, x, y);
    horizontalLine(size, x, y - (size / 2));
    horizontalLine(size, x, y - size);

    // Char F
    x += size * 2; // Space between the letters
    verticalLine(size, x, y);
    horizontalLine(size, x, y);
    horizontalLine(size, x, y - (size / 2));

    // Char F
    x += size * 2; // Space between the letters
    verticalLine(size, x, y);
    horizontalLine(size, x, y);
    horizontalLine(size, x, y - (size / 2));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawMyName(20, WIDTH / 4, HEIGHT / 2);
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Nome");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
