#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLint WIDTH = 600, HEIGHT = 600;

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT );
    glutCreateWindow("Laberinto 0.1");

    // glutDisplayFunc(Display);
    // glutReshapeFunc(Reshape);
    // glutKeyboardFunc(Keyboard);

    glutMainLoop();


    return 0;
}