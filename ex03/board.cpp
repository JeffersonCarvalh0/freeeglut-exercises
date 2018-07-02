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

/**
    Draws the board. It recieves the coordinates of the bottom left corner,
    que size of each square, the order of the border and its colors.

    @param x The x coordinate of the bottom left corner.
    @param y The y coordinate of the bottom left corner.
    @param square_size The size of each square of the board
    @param order The size of the board. It will be composed of order^2 squares(like a matrix).
    @param color1 An array of 3 floats representing the RGB of the first color of the board.
    @param color2 An array of 3 floats representing the RGB of the second color of the board.
*/
void drawTable(int x, int y, int square_size, int order, float *color1, float *color2) {
    float *cur_color, *last_color = color2;
    int new_x = x;

    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            cur_color = !((i + j) & 1) ? color1 : color2;
            drawSquare(new_x, y, square_size, cur_color);
            new_x += square_size;
            last_color = cur_color;
        }
        y += square_size;
        new_x = x;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float color1[3] = { 1.0, 0.0, 0.0 };
    float color2[3] = { 1.0, 1.0, 1.0 };
    drawTable(20, 20, 50, 5, color1, color2);
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
