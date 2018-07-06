# include <GL/glut.h>

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

    glRotatef(rotate, 1, 0, 0);

    glColor3f(1, 0.5, 0);

    // Perna 1
    glPushMatrix();
        glScalef(0.5, 3, 0.7);
        glTranslatef(-10, 0, 0);
        glutSolidCube(4);
    glPopMatrix();

    // Perna 2
    glPushMatrix();
        glScalef(0.5, 3, 0.7);
        glTranslatef(10, 0, 0);
        glutSolidCube(4);
    glPopMatrix();

    // TAMPA
    glColor3f(0.8, 0.5, 0.3);
    glPushMatrix();
        glScalef(4, 0.1, 2);
        glTranslatef(0, 58, 0);
        glutSolidCube(4);
    glPopMatrix();

    glColor3f(0.9, 0.8, 0.5);
    glPushMatrix();
        glTranslatef(0, 7.5, 0);
        glutSolidTeapot(2);
    glPopMatrix();

    glFlush();
}

void keyPressed(unsigned char Key, int x, int y){
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
    glutCreateWindow("Table");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
