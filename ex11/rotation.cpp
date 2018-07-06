# include <GL/glut.h>
# include <iostream>

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;
int current_x = 15;
int current_y = 0;
int angle = 0;
const int speed = 10;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

    glRotatef(rotate, 1, 0, 0);

    glColor3f(1, 0.5, 0);

    // Central sphere
    glPushMatrix();
        glutWireSphere(2, 20, 20);
    glPushMatrix();

    // Rotating sphere
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glTranslatef(current_x, current_y, 0);
        glutWireSphere(2, 20, 20);
    glPushMatrix();

    glFlush();
}

void keyPressed(unsigned char Key, int x, int y){
    rotate += 10;
    glutPostRedisplay();
}

int start = 0;

void animate() {
    int end = glutGet(GLUT_ELAPSED_TIME);
    if (end - start >= speed) {
        angle = (angle + 1) % 360;

        start = glutGet(GLUT_ELAPSED_TIME);
        glutPostRedisplay();
    }
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
    glutIdleFunc(animate);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
