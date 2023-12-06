#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "./constants.cpp"
#include "./classes/ClassNpc.cpp"
#include "./classes/ClassBox.cpp"
#include "./handlers/MouseAction.cpp"
#include "./handlers/KeyboardAction.cpp"




void renderSpace(int coor_x, int coor_y, int size) {
    glBegin(GL_QUADS);
        glVertex2f(coor_x, coor_y + size);
        glVertex2f(coor_x, coor_y);
        glVertex2f(coor_x + size, coor_y);
        glVertex2f(coor_x + size, coor_y + size);
    glEnd();
}



void RenderDisplay() {
    Box box(100);
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,255);
    box.render();
    renderSpace(0,0, SIZE_SPACE);
    renderSpace(100,200, SIZE_SPACE);
    renderSpace(50,80, SIZE_SPACE);

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