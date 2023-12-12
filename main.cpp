#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include "./constants.cpp"

//Canvas
#include "./classes/ClassCanvas.cpp"
//Game
// #include "./classes/ClassGame.cpp"


//Entity
#include "./classes/ClassEntity.cpp"
//Treasure
// #include "./classes/ClassTreasure.cpp"
//Dragon
// #include "./classes/ClassDragon.cpp"
//Gnome
// #include "./classes/ClassDragon.cpp"
//Player
//Keyboard
//Ceil
#include "./classes/ClassCeil.cpp"
//Wall
//Maze
#include "./classes/ClassMaze.cpp"
//app


Canvas canvas;
Entity player(START_X, START_Y , SIZE, SIZE);
Maze laberinto(SIZE, WIDTH, HEIGHT);


void renderSpace(int coor_x, int coor_y, int size) {
    glBegin(GL_QUADS);
        glVertex2f(coor_x, coor_y + size);
        glVertex2f(coor_x, coor_y);
        glVertex2f(coor_x + size, coor_y);
        glVertex2f(coor_x + size, coor_y + size);
    glEnd();
}



void RenderDisplay() {
    glClearColor(BGRED, BGGREEN, BGBLUE, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    laberinto.render( canvas );
    player.render( canvas );
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

void KeyboardAction(unsigned char key, int x, int y) {

    int position;
    switch( key ) {
        case 'q':
        case 'Q':
            exit(0);
            break;
        case UP:
            position = player.moveUp(SLOW_STEP);
            if( position > HEIGHT-2*SIZE || !laberinto.isFree(player) ) {
                player.moveDown(SLOW_STEP);
            }
            break;
        case DOWN:
            position = player.moveDown(SLOW_STEP);
            if( position < SIZE || !laberinto.isFree(player)  ) {
                player.moveUp(SLOW_STEP);
            }
            break;
        case LEFT:
            position = player.moveLeft(SLOW_STEP);
            if( position < SIZE || !laberinto.isFree(player)  ) {
                player.moveRight(SLOW_STEP);
            }
            break;
        case RIGHT:
            position = player.moveRight(SLOW_STEP);
            if( position > WIDTH-2*SIZE || !laberinto.isFree(player)  ) {
                player.moveLeft(SLOW_STEP);
            }
            break;
    }
    RenderDisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH + 200, HEIGHT );
    glutCreateWindow(TITLE);

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(KeyboardAction);

    glutMainLoop();

    return 0;
}