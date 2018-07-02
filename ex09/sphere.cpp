# include <GL/glut.h>

# define WIDTH 800
# define HEIGHT 600

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    glFrustum (-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
        glColor3f(1, 1, 1);
        glutSolidSphere(4, 30, 30);
    glPopMatrix();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sphere");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
