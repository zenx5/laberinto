class Ceil {

    Ceil( int type, int x, int y) {
        this->x = x;
        this->y = y;
        if( type === WALL || type===FREE || type===START || type===END )  {
            this->type = type;
        }else {
            this->type = FREE;
        }
        this->belowToPath = false;
        this->from = null;
    }

    setType( int type ) {
        this->type = type;
    }
}