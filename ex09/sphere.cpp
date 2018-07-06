# include <GL/glut.h>

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

    glRotatef(rotate, 1, 0, 0);

    glPushMatrix();
        glColor3f(1, 1, 1);
        glutWireSphere(4, 30, 30);
    glPopMatrix();

    glFlush();
}

void keyPressed(unsigned char Key, int x, int y) {
    rotate += 10;
    glutPostRedisplay();
}

void reshape (int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sphere");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
