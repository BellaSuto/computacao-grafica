#include <gl/glut.h>
#include <gl/glu.h>
#include <stdio.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Corpo do tanque
    glColor3f(1.0f, 0.8f, 0.9f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.2f); // Inferior esquerdo
        glVertex2f(0.3f, -0.2f);  // Inferior direito
        glVertex2f(0.3f, 0.2f);   // Superior direito
        glVertex2f(-0.3f, 0.2f);  // Superior esquerdo
    glEnd();

    // Torre do tanque
    glColor3f(1.0f, 0.5f, 0.7f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f); // Inferior esquerdo
        glVertex2f(0.1f, -0.1f);  // Inferior direito
        glVertex2f(0.1f, 0.1f);   // Superior direito
        glVertex2f(-0.1f, 0.1f);  // Superior esquerdo
    glEnd();

    // Canhão do tanque 
    glColor4f(0.576f, 0.133f, 0.722f, 0.8f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.04f, 0.1f);   // Inferior esquerdo
        glVertex2f(0.04f, 0.1f);    // Inferior direito
        glVertex2f(0.04f, 0.4f);    // Superior direito
        glVertex2f(-0.04f, 0.4f);   // Superior esquerdo
    glEnd();

    // Rodas do tanque 
    glColor3f(0.9f, 0.7f, 1.0f);

    // Roda esquerda
    glBegin(GL_QUADS);
        glVertex2f(-0.35f, -0.25f); // Inferior esquerdo
        glVertex2f(-0.25f, -0.25f); // Inferior direito
        glVertex2f(-0.25f, 0.25f);  // Superior direito
        glVertex2f(-0.35f, 0.25f);  // Superior esquerdo
    glEnd();

    // Roda direita
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.25f);  // Inferior esquerdo
        glVertex2f(0.35f, -0.25f);  // Inferior direito
        glVertex2f(0.35f, 0.25f);   // Superior direito
        glVertex2f(0.25f, 0.25f);   // Superior esquerdo
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Cor de fundo
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Projeção ortogonal
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Girly Tank 2D");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
