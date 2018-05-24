# include <GL/glut.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

int currentX = (WIDTH / 2);
int currentY = (HEIGHT / 2);
int currentAngle = 0;

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

void T(int x, int y, int size, float *color) {
    drawSquare(x, y, size, color);
    drawSquare(x + size, y, size, color);
    drawSquare(x + size, y + size, size, color);
    drawSquare(x + (size * 2), y, size, color);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float cyan[3] = { 0.0, 1.0, 1.0 };

    glPushMatrix();
        glTranslatef(currentX, currentY, 0);
        glRotatef(currentAngle, 0, 0, 1);
        glTranslatef(-(currentX + 30), -(currentY + 30), 0);
        T(currentX, currentY, 20, cyan);
    glPopMatrix();
    glFlush();
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': currentY = (currentY + 20) % HEIGHT; break;
        case 'a': currentX -= 20; if (currentX < 0) currentX += WIDTH; break;
        case 's': currentY -= 20; if (currentY < 0) currentY += HEIGHT; break;
        case 'd': currentX = (currentX + 20) % WIDTH; break;
        case 'q': currentAngle = (currentAngle + 90) % 360; break;
        case 'e': currentAngle = (currentAngle - 90) % 360; break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Move");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
