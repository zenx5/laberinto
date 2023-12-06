class Maze {
    public:
        int columns, rows, walls, entities;

        Maze(int columns, int rows){
            this.columns = columns;
            this.rows = rows;
        }

        void addEntity(int index, int entity) {
            this.entity[ index ] = entity;
        }

        void addCeil( int type, int x, int y ) {
            this.ceils[y][x] = new Ceil( type, x, y );
        }

        void generate( void ) {
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
            this->ceils[this.rows-2][this.columns-2] = new Ceil( END, this.columns-2, this.rows-2 );

            //generamos el camino que une el inicio con el fin y las bifurcaciones
            this.addCeilToPath( this.ceils[1][1], null, this.ceils[this.rows-2][this.columns-2], 0 )
        }


};