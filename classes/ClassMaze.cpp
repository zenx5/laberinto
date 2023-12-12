class Maze {
    int width, height, size;
    int **entities;
    Ceil **ceils;
    public:
        Maze(int size, int width, int height){
            this->width = width/size;
            this->height = height/size;
            this->size = size;
            int **temp;
            Ceil **temp2;
            Ceil ceil(FREE, 0, 0);
            temp = new int*[width];
            temp2 = new Ceil*[width];
            for( int i=0; i < width; i++) {
                temp[i] = new int[height];
                temp2[i] = new Ceil[height];
            }

            this->entities = temp;
            this->ceils = temp2;

            for( int i=0; i < this->width; i++) {
                for( int j=0; j < this->height; j++) {
                    if( i==0 || i==this->width-1 || j==0 || j==this->height-1 ) {
                        this->entities[i][j] = WALL;
                        this->ceils[i][j] = Ceil(WALL, i, j);
                        this->ceils[5][5] = Ceil(WALL, i, j);
                                    this->ceils[8][5] = Ceil(WALL, i, j);
                        this->ceils[5][6] = Ceil(WALL, i, j);
                                    this->ceils[8][6] = Ceil(WALL, i, j);
                        this->ceils[5][7] = Ceil(WALL, i, j);
                                    this->ceils[8][7] = Ceil(WALL, i, j);
                        this->ceils[5][8] = Ceil(WALL, i, j);
                            this->ceils[6][8] = Ceil(WALL, i, j);
                                this->ceils[7][8] = Ceil(WALL, i, j);
                                    this->ceils[8][8] = Ceil(WALL, i, j);
                        this->ceils[5][9] = Ceil(WALL, i, j);
                                    this->ceils[8][9] = Ceil(WALL, i, j);
                        this->ceils[5][10] = Ceil(WALL, i, j);
                                    this->ceils[8][10] = Ceil(WALL, i, j);
                        this->ceils[5][11] = Ceil(WALL, i, j);
                            this->ceils[6][11] = Ceil(WALL, i, j);
                                this->ceils[7][11] = Ceil(WALL, i, j);
                                    this->ceils[8][11] = Ceil(WALL, i, j);
                    } else {
                        this->entities[i][j] = FREE;
                        this->ceils[i][j] = Ceil(FREE, i, j);
                    }
                }
            }
            this->entities[1][1] = START;
            this->ceils[1][1] = Ceil(START, 1, 1);
            this->entities[this->width-2][this->height-2] = END;
            this->ceils[this->width-2][this->height-2] = Ceil(END, 1, 1);

            // this->addCeilToPath( this->ceils[1][1], null, this->ceils[this->rows-2][this->columns-2], 0 )
        }

        bool isFree(Entity entity) {
            int type = this->ceils[entity.x/this->size][entity.y/this->size].type;
            return type==FREE || type==START || type==END;
        }


        // void addCeilToPath(Ceil currentCeil, Ceil fromCeil, Ceil toCeil ) {
        //      if( currentCeil.belowToPath ) {
        //         return;
        //     }
        //     currentCeil.belowToPath = true;

        //     int directions[4] = {UP, DOWN, LEFT, RIGHT};
        //     // .sort( () => Math.random() - 0.5 );


        //     for( int i = 0; i < 4; i++ ) {
        //         Ceil nextCeil;
        //         nextCeil = this->getNextCeil( currentCeil, directions[i] );
        //         if( !nextCeil.belowToPath ) {
        //             nextCeil.belowToPath = true;
        //             nextCeil.from = &currentCeil;

        //             this->addCeil( FREE, (currentCeil.x + nextCeil.x) / 2, (currentCeil.y + nextCeil.y) / 2 );
        //             this->addCeilToPath( nextCeil, currentCeil, to );
        //         }
        //     }
        // }

        Ceil getNextCeil(Ceil currentCeil, int direction) {
            int x = currentCeil.x;
            int y = currentCeil.y;
            switch( direction ) {
                case UP:
                    y-=2;
                    break;
                case DOWN:
                    y+=2;
                    break;
                case LEFT:
                    x-=2;
                    break;
                case RIGHT:
                    x+=2;
                    break;
            }
            if( this->pointBelowToBoard( x, y) ) {
                return this->ceils[y][x];
            }
            return this->ceils[y][x];
        }

        bool pointBelowToBoard( int x, int y ) {
            return x >= 0 && x < this->width && y >= 0 && y < this->height;
        }

        void generate(){

        }

        void render(Canvas canvas) {
            for( int i=0; i < this->width; i++) {
                for( int j=0; j < this->height; j++) {
                    if( this->ceils[i][j].type==WALL ) {
                        int color[] = {255,255,255};
                        canvas.drawRect( i*this->size, j*this->size, this->size, this->size, color);
                        int lcolor[] = {0,0,0};
                        canvas.drawRect( i*this->size+2, j*this->size+2, this->size-2, this->size-2, lcolor);
                    }
                    else if( this->ceils[i][j].type==START ) {
                        int color[] = {255,255,255};
                        canvas.drawRect( i*this->size, j*this->size, this->size, this->size, color);
                        int lcolor[] = {255,100,100};
                        canvas.drawRect( i*this->size+2, j*this->size+2, this->size-2, this->size-2, lcolor);
                    }
                    else if( this->ceils[i][j].type==END ) {
                        int color[] = {255,255,255};
                        canvas.drawRect( i*this->size, j*this->size, this->size, this->size, color);
                        int lcolor[] = {255,100,255};
                        canvas.drawRect( i*this->size+2, j*this->size+2, this->size-2, this->size-2, lcolor);
                    }
                }
            }
        }


};

/*class Maze {
    public:
        int columns, rows, walls, entities;

        Maze(int columns, int rows){
            this->columns = columns;
            this->rows = rows;
            this->ceils
        }

        void addEntity(int index, int entity) {
            this->entity[ index ] = entity;
        }

        void addCeil( int type, int x, int y ) {
            this->ceils[y][x] = new Ceil( type, x, y );
        }

        Ceil[] generate( void ) {
            for( int x = 0; x < this->columns; x++ ) {
                for( int y = 0; y < this->rows; y++ ) {
                    if( x % 2 === 0 || y % 2 === 0 ) {
                        this->addCeil( WALL, x, y );
                    }
                    else {
                        this->addCeil( FREE, x, y );
                    }
                }
            }
            this->ceils[1][1] = new Ceil( START, 1, 1 );
            this->ceils[this->rows-2][this->columns-2] = new Ceil( END, this->columns-2, this->rows-2 );

            //generamos el camino que une el inicio con el fin y las bifurcaciones
            this->addCeilToPath( this->ceils[1][1], null, this->ceils[this->rows-2][this->columns-2], 0 )

            return this->ceils
        }

        void addCeilToPath(Ceil currentCeil, fromCeil, toCeil ) {
             if( currentCeil.belowToPath ) {
                return;
            }
            currentCeil.belowToPath = true;

            int directions[4] = {UP, DOWN, LEFT, RIGHT};
            // .sort( () => Math.random() - 0.5 );


            for( int i = 0; i < 4; i++ ) {
                Ceil nextCeil = this->getNextCeil( currentCeil, directions[i] );
                if( nextCeil && !nextCeil.belowToPath ) {
                    // console.log('paso en la condicion de existencia de nextCeil')
                    // nextCeil.belowToPath = true;
                    nextCeil.from = currentCeil;

                    //Hacer que la celda que esta entre currentCeil y nextCeil se marque como free
                    this->addCeil( 'free', (currentCeil.x + nextCeil.x) / 2, (currentCeil.y + nextCeil.y) / 2 );
                    // console.log(nextCeil, currentCeil, to)
                    this->addCeilToPath( nextCeil, currentCeil, to, i+1 );
                }
            }
        }

        Ceil getNextCeil(Ceil currentCeil, int direction) {
            int x = currentCeil.x;
            int y = currentCeil.y;
            switch( direction ) {
                case UP:
                    y-=2;
                    break;
                case DOWN:
                    y+=2;
                    break;
                case LEFT:
                    x-=2;
                    break;
                case RIGHT:
                    x+=2;
                    break;
            }
            if( this->pointBelowToBoard( x, y) ) {
                return this->ceils[y][x];
            }

            bool pointBelowToBoard( x, y ) {
                return x >= 0 && x < this->columns && y >= 0 && y < this->rows;
            }
        }


};*/