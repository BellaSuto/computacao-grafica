#include <gl/glut.h>
#include <gl/glu.h>
#include <stdio.h>
#include <cmath>

// Variáveis para a rotação do tanque
float angleX = 0.0f, angleY = 0.0f;
float lastMouseX, lastMouseY;
bool mouseDown = false;

void drawCylinder(GLfloat radius, GLfloat height) {
    GLUquadric *quadric = gluNewQuadric();
    gluCylinder(quadric, radius, radius, height, 32, 32);
    gluDeleteQuadric(quadric);
}

void drawTank() {
    // Corpo do tanque
    glPushMatrix();
    glColor3f(1.0f, 0.8f, 0.9f);
    glScalef(1.0f, 0.5f, 1.2f); 
    glutSolidCube(1.0f);
    glPopMatrix();

    // Torre do tanque
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.7f);
    glTranslatef(0.0f, 0.3f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotação da torre
    glScalef(0.5f, 0.3f, 0.5f); 
    glutSolidCube(1.0f);
    glPopMatrix();

    // Canhão do tanque
    glPushMatrix();
    glColor4f(0.576f, 0.133f, 0.722f, 0.8f);
    glTranslatef(0.0f, 0.3f, 0.3f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f); 
    drawCylinder(0.05f, 1.0f);
    glPopMatrix();

    // Esteiras do tanque - Esquerda
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(-0.6f, -0.25f, 0.0f);
    glScalef(0.1f, 0.2f, 1.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Esteiras do tanque - Direita
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(0.6f, -0.25f, 0.0f);
    glScalef(0.1f, 0.2f, 1.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Rodas do tanque - Esquerda
    for (int i = -1; i <= 2; i++) {
        glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(-0.7f, -0.3f, -0.14 + i * 0.4f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        drawCylinder(0.15f, 0.1f);
        glPopMatrix();
    }

    // Rodas do tanque - Direita
    for (int i = -1; i <= 2; i++) {
        glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(0.6f, -0.3f, -0.14 +i * 0.4f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        drawCylinder(0.15f, 0.1f);
        glPopMatrix();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    drawTank();

    glutSwapBuffers();
}

void idle() {
    angleY += 0.1f;
    if (angleY > 360.0f) angleY -= 360.0f;
    glutPostRedisplay();
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        angleY += (x - lastMouseX) * 0.3f;
        angleX += (y - lastMouseY) * 0.3f;
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        lastMouseX = x;
        lastMouseY = y;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        mouseDown = false;
    }
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tank 3D");

    init();

    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();

    return 0;
}
