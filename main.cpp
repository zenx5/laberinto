#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "./constants.cpp"
#include "./handlers/MouseAction.cpp"
#include "./handlers/KeyboardAction.cpp"



int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT );
    glutCreateWindow(TITLE);

    // glutDisplayFunc(Display);
    // glutReshapeFunc(Reshape);
    glutKeyboardFunc(KeyboardAction);
    glutMouseFunc(MouseAction);

    glutMainLoop();


    return 0;
}