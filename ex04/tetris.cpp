# include <GL/glut.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

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

void line (int x, int y, int size, float *color) {
    drawSquare(x, y, size, color); x += size;
    drawSquare(x, y, size, color); x += size;
    drawSquare(x, y, size, color); x += size;
    drawSquare(x, y, size, color); x += size;
}

void block(int x, int y, int size, float *color) {
    drawSquare(x, y, size, color);
    drawSquare(x + size, y, size, color);
    drawSquare(x, y + size, size, color);
    drawSquare(x + size, y + size, size, color);
}

void T(int x, int y, int size, float *color) {
    drawSquare(x, y, size, color);
    drawSquare(x + size, y, size, color);
    drawSquare(x + size, y + size, size, color);
    drawSquare(x + (size * 2), y, size, color);
}

void S(int x, int y, int size, float *color) {
    drawSquare(x, y, size, color);
    drawSquare(x + size, y, size, color);
    drawSquare(x + size, y + size, size, color);
    drawSquare(x + (size * 2), y + size, size, color);
}

void L(int x, int y, int size, float *color) {
    drawSquare(x, y, size, color);
    drawSquare(x, y + size, size, color);
    drawSquare(x + size, y, size, color);
    drawSquare(x + (size * 2), y, size, color);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float blue[3] = { 0.0, 0.0, 1.0 };
    float yellow[3] = { 1.0, 1.0, 0.0 };
    float cyan[3] = { 0.0, 1.0, 1.0 };
    float red[3] = { 1.0, 0.0, 0.0 };
    float magenta[3] = { 1.0, 0.0, 1.0 };

    line(10, 10, 20, blue);
    block(110, 10, 20, yellow);
    T(160, 10, 20, cyan);
    S(240, 10, 20, red);
    L(320, 10, 20, magenta);

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Board");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
