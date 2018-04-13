# include <GL/glut.h>

# define WIDTH 256
# define HEIGHT 256

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

/**
    Draws a star in the screen.
    @param size An integer representing the size of the star.
    @param x An integer representing the x coordinate of the center of the star.
    @param y An integer representing the y coordinate of the center of the star.
*/
void star(int size, int x, int y) {
    glBegin(GL_LINE_STRIP);
        glVertex2i(x - (size / 2), y - (size / 2)); // 1
        glVertex2i(x, y + (size / 2));              // 2
        glVertex2i(x + (size / 2), y - (size / 2)); // 3
        glVertex2i(x - (size / 2), y + (size / 6)); // 4
        glVertex2i(x + (size / 2), y + (size / 6)); // 5
        glVertex2i(x - (size / 2), y - (size / 2)); // 1
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    star(100, WIDTH / 2, HEIGHT / 2);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Star");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
