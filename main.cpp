#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "./constants.cpp"
#include "./handlers/MouseAction.cpp"
#include "./handlers/KeyboardAction.cpp"


void RenderDisplay() {

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0,255,255);
    glBegin(GL_QUADS);
        glVertex2f(100,300);
        glVertex2f(100,100);
        glVertex2f(300,100);
        glVertex2f(300,300);
    glEnd();
    glFinish();
}

void Reshape(GLint w, GLint h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT );
    glutCreateWindow(TITLE);

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(KeyboardAction);
    glutMouseFunc(MouseAction);

    glutMainLoop();


    return 0;
}