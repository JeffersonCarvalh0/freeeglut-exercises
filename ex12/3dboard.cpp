# include <GL/glut.h>

# define WIDTH 800
# define HEIGHT 600

int rotate = 0;

void drawSquare(int x, int y, int size, float *color) {
    glColor3f(color[0], color[1], color[2]);

    glPushMatrix();
        glTranslatef(x, y, 0);
        glutSolidCube(size);
    glPopMatrix();
}

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
    glLoadIdentity();
    glFrustum (-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

    float color1[3] = { 1.0, 0.0, 0.0 };
    float color2[3] = { 1.0, 1.0, 1.0 };

    glRotatef(rotate, 1, 0, 0);

    drawTable(-5, 0, 2, 6, color1, color2);

    glFlush();
}

void keyPressed(unsigned char Key, int x, int y){
    rotate += 10;
    glutPostRedisplay();
}

int start = 0;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Table");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
