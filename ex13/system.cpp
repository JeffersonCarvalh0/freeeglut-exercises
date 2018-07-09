# include <GL/glut.h>
# include <SOIL/SOIL.h>
# include <iostream>
# include "planet.hpp"

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;
const int speed = 10;

enum TexCodes { SUN, MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, SATURN_RING, URANUS, NEPTUNE };

GLuint textures[10];
void loadGLTextures() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    textures[SUN] = SOIL_load_OGL_texture("2k_sun.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[MERCURY] = SOIL_load_OGL_texture("2k_mercury.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[VENUS] = SOIL_load_OGL_texture("2k_venus_surface.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[EARTH] = SOIL_load_OGL_texture("2k_earth_daymap.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[MARS] = SOIL_load_OGL_texture("2k_mars.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[JUPITER] = SOIL_load_OGL_texture("2k_jupiter.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[SATURN] = SOIL_load_OGL_texture("2k_saturn.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[SATURN_RING] = SOIL_load_OGL_texture("2k_saturn_ring_alpha.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[URANUS] = SOIL_load_OGL_texture("2k_uranus.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[NEPTUNE] = SOIL_load_OGL_texture("2k_neptune.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Planet planets[9];
void createPlanets() {
    planets[0] = Planet(textures[SUN], 2);
    planets[1] = Planet(textures[MERCURY], 0.1, 3, 1200, 720);
    planets[2] = Planet(textures[VENUS], 0.3, 6, 273.923, 282);
    planets[3] = Planet(textures[EARTH], 0.3, 9, 64.285, 173);
    planets[4] = Planet(textures[MARS], 0.2, 12, 600, 92.28);
    planets[5] = Planet(textures[JUPITER], 1, 15, 156.521, 12.28);
    planets[6] = Planet(textures[SATURN], 0.8, 18, 138.461, 5.88, true);
    planets[7] = Planet(textures[URANUS], 0.7, 21, 90, 2.04);
    planets[8] = Planet(textures[NEPTUNE], 0.6, 24, 97.287, 1.04);
}

void keyPressed(unsigned char Key, int x, int y){
    rotate += 10;
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 35, 0, 0, 0, 0, 1, 0);

    glRotatef(rotate, 1, 0, 0);
    for (int i = 0; i < 9; ++i) planets[i].draw();
    glFlush();
}

float start = 0;
float total_time = 0;
void animate() {
    float end = glutGet(GLUT_ELAPSED_TIME);
    if (end - start >= speed) {
        total_time += (end - start) / 1000;
        for (int i = 0; i < 9; ++i) planets[i].move(total_time);
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
    loadGLTextures();
    createPlanets();
    glutMainLoop();
    return 0;
}
