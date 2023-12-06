class Box : public NPC {
    public:

        Box(int size){
            this->size = size;
        }

        void render(){
            glBegin(GL_QUADS);
                glVertex2f(this->coor_x, this->coor_y + this->size);
                glVertex2f(this->coor_x, this->coor_y);
                glVertex2f(this->coor_x + this->size, this->coor_y);
                glVertex2f(this->coor_x + this->size, this->coor_y + this->size);
            glEnd();
        }
};