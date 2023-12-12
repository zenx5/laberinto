#define FREE 0
#define WALL 1
#define START 2
#define END 3
#define SLOW_STEP 20
#define SIZE 20
#define START_X 20
#define START_Y 20
#define UP '8'
#define DOWN '5'
#define LEFT '4'
#define RIGHT '6'
#define FILL true
#define NOTFILL false
#define BGRED 255
#define BGGREEN 255
#define BGBLUE 255
//Entidades
#define ENTITY 1
#define TREASURE 2
#define DRAGON 3

#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

const char* TITLE = "Laberinto 0.1";
GLint WIDTH = 600, HEIGHT = 600;
int SIZE_SPACE = 30;
