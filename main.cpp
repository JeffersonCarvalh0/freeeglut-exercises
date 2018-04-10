# include <GL/glut.h>
# include <cstdlib>

using namespace std;

void init();
void display();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenhando uma linha");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex2i(40, 200);
        glVertex2i(200, 40);
    glEnd();
    glFlush();
}
