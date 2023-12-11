class NPC {
    public:
        int coor_x=0, coor_y=0, size=0;

        void moveUp(int steps){
            this->coor_y += steps * this->size;
        }

        void moveDown(int steps){
            this->coor_y -= steps * this->size;
        }

        void moveLeft(int steps){
            this->coor_x -= steps * this->size;
        }

        void moveRight(int steps){
            this->coor_x += steps * this->size;
        }

        static void render();
};