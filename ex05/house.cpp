# include <GL/glut.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
}

void drawSquare(float x, float y, float size, float *color) {
    glBegin(GL_QUADS);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glVertex2f(x, y + size);
        glVertex2f(x + size, y + size);
        glVertex2f(x + size, y);
    glEnd();
}

void drawRectangle(float x, float y, float size_x, float size_y, float *color) {
    glBegin(GL_QUADS);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glVertex2f(x + size_x, y);
        glVertex2f(x + size_x, y + size_y);
        glVertex2f(x, y + size_y);
    glEnd();
}

void drawTriangle(float x, float y, float size, float *color) {
    glBegin(GL_TRIANGLES);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f((x + (x + size))/2, y + sqrt(pow(size, 2) - pow((x + size/2) - x, 2)));
    glEnd();
}

void drawParallelogram(float x1, float y1, float x2, float y2, float size, float *color) {
    glBegin(GL_POLYGON);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x2 + size, y2);
        glVertex2f(x1 + size, y1);
    glEnd();
}

void drawWindow(float x, float y, float size, float *color1, float *color2) {
    drawSquare(x, y, size, color1);

    glBegin(GL_LINES);
        glColor3f(color2[0], color2[1], color2[2]);
        glVertex2f(x + (size/2), y + size);
        glVertex2f(x + (size/2), y);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(color2[0], color2[1], color2[2]);
        glVertex2f(x, y + (size/2));
        glVertex2f(x + size, y + (size/2));
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float yellow[3] = { 1.0, 1.0, 0.0 };
    float red[3] = { 1.0, 0.0, 0.0 };
    float darkerYellow[3] = { 0.7, 0.7, 0.0 };
    float darkerRed[3] = { 0.7, 0.0, 0.0 };
    float orange[3] = { 1.0, 0.4, 0.0 };
    float blue[3] = { 0.0, 0.0, 1.0 };
    float darkerBlue[3] = { 0.0, 0.0, 0.7 };
    float black[3] = { 0.0, 0.0, 0.0 };

    int x = 100, y = 100, size = 200;
    int x1 = x + size, y1 = y + size;
    int x2 = (x + (x + size)) / 2, y2 = (y + size) + sqrt(pow(size, 2) -  pow((x + size/2) - x, 2));

    // Walls and tiling
    drawSquare(x, y, size, yellow);
    drawRectangle(x + size, y, size * 2, size, darkerYellow);
    drawTriangle(x, y + size, size, red);
    drawParallelogram(x1, y1, x2, y2, size * 2, darkerRed);

    // Door and windows
    drawRectangle(x + (size/6), y, size/3, (size/2) + (size/4), orange);
    drawSquare(x + (size/6) + (size/4), y + (size/3), size/16, black);
    drawWindow(x + (size/2) + (size/8), y + (size/3), size/4, blue, black);
    drawWindow(x + size + (size/2), y + (size/3), size/4, darkerBlue, black);
    drawWindow(x + (size*2) + (size/4), y + (size/3), size/4, darkerBlue, black);


    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
