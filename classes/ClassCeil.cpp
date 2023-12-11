class Ceil {
    public:
        int type, x, y;
        bool belowToPath;
        Ceil *from;

        Ceil() {
            this->x = x;
            this->y = y;
            this->type = FREE;
            this->belowToPath = false;
        }

        Ceil( int type, int x, int y) {
            this->x = x;
            this->y = y;
            if( type == WALL || type==FREE || type==START || type==END )  {
                this->type = type;
            }else {
                this->type = FREE;
            }
            this->belowToPath = false;
        }

        void setType( int type ) {
            this->type = type;
        }
};