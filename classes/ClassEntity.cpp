class Entity {
    public:
        int type = ENTITY;
        int x, y, width, height, coins = 0;
        Entity(int x, int y, int width, int height) { // game:Game, x:int, y:int, width:int, height:int
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            //game->entities.push( this );
        }

        void render( Canvas canvas ) {
            int color[] = {0,0,255};
            canvas.drawRect( this->x, this->y, this->width, this->height, color);
        };

        int moveUp(int steps){
            this->y += steps;
            return this->y;
        }

        int moveDown(int steps){
            this->y -= steps;
            return this->y;
        }

        int moveLeft(int steps){
            this->x -= steps;
            return this->x;
        }

        int moveRight(int steps){
            this->x += steps;
            return this->x;
        }
};