# include <GL/glut.h>
# include <iostream>
# include "planet.hpp"

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;
const int speed = 10;

float yellow[3] = { 1, 1, 0 };
float light_grey[3] = { 0.5, 0.5, 0.5 };
float lavander_blush[3] = { 1, 0.941, 0.961 };
float sky_blue[3] = { 0.529, 0.808, 0.922 };
float tomato[3] = { 1, 0.388, 0.278 };
float pale_goldenrod[3] = { 0.933, 0.910, 0.667 };
float pale_turquose[3] = { 0.686, 0.933, 0.933 };
float medium_blue[3] = { 0, 0, 0.804 };

Planet sun(yellow, 2);
Planet mercury(light_grey, 0.1, 3, 1200, 720);
Planet venus(lavander_blush, 0.3, 6, 273.923, 282);
Planet earth(sky_blue, 0.3, 9, 64.285, 173);
Planet mars(tomato, 0.2, 12, 600, 9.228);
Planet jupiter(pale_goldenrod, 1, 15, 156.521, 12.28);
Planet saturn(pale_goldenrod, 0.8, 18, 138.461, 5.88, true);
Planet uranus(pale_turquose, 0.7, 21, 90, 2.04);
Planet neptune(medium_blue, 0.6, 24, 97.287, 1.04);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 35, 0, 0, 0, 0, 1, 0);

    glRotatef(rotate, 1, 0, 0);

    sun.draw();
    mercury.draw();
    venus.draw();
    earth.draw();
    mars.draw();
    jupiter.draw();
    saturn.draw();
    uranus.draw();
    neptune.draw();

    glFlush();
}

void keyPressed(unsigned char Key, int x, int y){
    rotate += 10;
    glutPostRedisplay();
}

float start = 0;
float total_time = 0;

void animate() {
    float end = glutGet(GLUT_ELAPSED_TIME);
    if (end - start >= speed) {
        total_time += (end - start) / 1000;
        mercury.move(total_time);
        venus.move(total_time);
        earth.move(total_time);
        mars.move(total_time);
        jupiter.move(total_time);
        saturn.move(total_time);
        uranus.move(total_time);
        neptune.move(total_time);

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
    glutCreateWindow("Solar System");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutIdleFunc(animate);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
