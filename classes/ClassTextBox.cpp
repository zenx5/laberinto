class TextBox {
    private:
        int pixel, x, y, color[3], bgColor[3];
        int currentX, currentY, space;
    public:
        TextBox(int pixel, int space) {
            this->pixel = pixel;
            this->space = space;
            this->setColor(255,255,255);
            this->setBgColor(0,0,0);
        }

        void setColor(int red, int green, int blue) {
            this->color[0] = red;
            this->color[1] = green;
            this->color[2] = blue;
        }

        void setBgColor(int red, int green, int blue) {
            this->bgColor[0] = red;
            this->bgColor[1] = green;
            this->bgColor[2] = blue;
        }

        void vertice(Canvas canvas,
            bool one, bool two, bool three,
            bool four, bool five, bool six,
            bool seven, bool eight, bool nine) {

            if( one ) {
                canvas.drawRect( this->currentX, this->currentY, this->pixel, this->pixel, this->color);
            }
            if( two ) {
                canvas.drawRect( this->currentX + 3*this->pixel, this->currentY, this->pixel, this->pixel, this->color);
            }
            if( three ) {
                canvas.drawRect( this->currentX + 6*this->pixel, this->currentY, this->pixel, this->pixel, this->color);
            }
            if( four ) {
                canvas.drawRect( this->currentX, this->currentY - 4*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( five ) {
                canvas.drawRect( this->currentX + 3*this->pixel, this->currentY - 4*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( six ) {
                canvas.drawRect( this->currentX + 6*this->pixel, this->currentY - 4*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( seven ) {
                canvas.drawRect( this->currentX, this->currentY - 8*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( eight ) {
                canvas.drawRect( this->currentX + 3*this->pixel, this->currentY - 8*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( nine ) {
                canvas.drawRect( this->currentX + 6*this->pixel, this->currentY - 8*this->pixel, this->pixel, this->pixel, this->color);
            }
        }

        void aristaExt(Canvas canvas,
            bool one, bool two,
            bool three, bool four,
            bool five, bool six,
            bool seven, bool eight) {

            if( one ) {
                canvas.drawRect( this->currentX + this->pixel, this->currentY, 2*this->pixel, this->pixel, this->color);
            }
            if( two ) {
                canvas.drawRect( this->currentX + 4*this->pixel, this->currentY, 2*this->pixel, this->pixel, this->color);
            }
            if( three ) {
                canvas.drawRect( this->currentX + 6*this->pixel, this->currentY - 3*this->pixel, this->pixel, 3*this->pixel, this->color);
            }
            if( four ) {
                canvas.drawRect( this->currentX + 6*this->pixel, this->currentY - 7*this->pixel, this->pixel, 3*this->pixel, this->color);
            }
            if( five ) {
                canvas.drawRect( this->currentX + 4*this->pixel, this->currentY - 8*this->pixel, 2*this->pixel, this->pixel, this->color);
            }
            if( six ) {
                canvas.drawRect( this->currentX + this->pixel, this->currentY - 8*this->pixel, 2*this->pixel, this->pixel, this->color);
            }
            if( seven ) {
                canvas.drawRect( this->currentX, this->currentY - 7*this->pixel, this->pixel, 3*this->pixel, this->color);
            }
            if( eight ) {
                canvas.drawRect( this->currentX, this->currentY - 3*this->pixel, this->pixel, 3*this->pixel, this->color);
            }
        }

        void aristaInt(Canvas canvas,
            bool one, bool two, bool three,
            bool four,          bool five,
            bool six,bool seven, bool eight) {
            int x = this->currentX + 3*this->pixel;
            int y = this->currentY - 4*this->pixel;
            if( one ) {
                canvas.drawRect( x, y, this->pixel, this->pixel*4, this->color);
            }
            if( two ) {
                canvas.drawRect( x, y, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + this->pixel, y + this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + this->pixel, y + 2*this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + 2*this->pixel, y + 3*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( three ) {
                canvas.drawRect( x, y, 3*this->pixel, this->pixel, this->color);
            }
            if( four ) {
                canvas.drawRect( x, y, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + this->pixel, y - this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + this->pixel, y - 2*this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x + 2*this->pixel, y - 3*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( five ) {
                canvas.drawRect( x, y, this->pixel, -3*this->pixel, this->color);
            }
            if( six ) {
                canvas.drawRect( x, y, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - this->pixel, y - this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - this->pixel, y - 2*this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - 2*this->pixel, y - 3*this->pixel, this->pixel, this->pixel, this->color);
            }
            if( seven ) {
                canvas.drawRect( x, y, -2*this->pixel, this->pixel, this->color);
            }
            if( eight ) {
                canvas.drawRect( x, y, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - this->pixel, y + this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - this->pixel, y + 2*this->pixel, this->pixel, this->pixel, this->color);
                canvas.drawRect( x - 2*this->pixel, y + 3*this->pixel, this->pixel, this->pixel, this->color);
            }
        }

        void setCurrent(int x, int y){
            this->currentX = x;
            this->currentY = y;
        }

        void setLetter(Canvas canvas, char letter, int x, int y) {
            this->setCurrent(x, y);
            switch(letter) {
                case 'A':
                case 'a':
                    this->vertice(canvas,false, true, false,true, true, true,true, false, true);
                    this->aristaExt(canvas,true, true,true, true,false, false,true, true);
                    this->aristaInt(canvas,false, false, true,false, false, false,true, false);
                    break;
                case 'B':
                case 'b':
                    this->vertice(canvas,true, true, false,true, true, false,true, true, false);
                    this->aristaExt(canvas,true, true,true, true,true, true,true, true);
                    this->aristaInt(canvas,false, false, true,false, false, false,true, false);
                    break;
                case 'C':
                case 'c':
                    this->vertice(canvas,false, true, true, true, false, false,false, true, true);
                    this->aristaExt(canvas,true, true,false, false,true, true,true, true);
                    this->aristaInt(canvas,false, false, false,false, false, false,false, false);
                    break;

            }

        }

        void setText(Canvas canvas, const char *text, int length, int x, int y) {
            int space = 0;
            for( int i = 0; i<length; i++) {
                char letter = text[i];
                this->setLetter(canvas, letter, x + i*(this->pixel*7 + this->space), y);
            }
        }
};