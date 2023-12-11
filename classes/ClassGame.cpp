class Game {
    int columns, rows, width, height, tileSize;
    Canvas canvas;
    Game(int size, container ) { //size:int, container:HTMLElement
        this->columns = size;
        this->rows = size;
        this->tileSize = 15;
        this->height = this->columns * this->tileSize;
        this->width = this->rows * this->tileSize;
        // this->maze = new Maze( this.columns, this.rows );
        // this->keyboard = new Keyboard( );
        // this->walls = [];
        // this->entities = [];
        // this->score = 0;
        // this->init( );
    }

    init( ) {
        this.walls = [];
        this.entities = [];
        this.score = 0;

        let ceils = this.maze.generate( )
        ceils.forEach( rows => {
            rows.forEach( ceil => {
                if( ceil.type === WALL ) {
                    let wall = new Wall( this.maze, ceil.x, ceil.y );
                    this.addWall( wall );
                }
            })
        })

        //colocamos las entidades en el laberinto, el usuario, los gnomos, los dragones y algunos tesoros
        this.createPlayer( );
        this.createCoins( 5 );
        this.createGnomes( 5 );
        this.createDragons( 5 );

        this.render( )
    }

    createPlayer( ) {
        new Player( this, 1, 1, this.tileSize, this.tileSize );
        //cada ves que el usuario se mueva, se actualiza el score
        window.addEventListener( 'keydown', e => {
            this.update( );
            this.render( )
        })
    }

    createCoins( numcoins ) {
        while( numcoins > 0 ) {
            int x = rand()/1000000000 * this.columns;
            int y = rand()/1000000000 * this.rows;
            if( this.maze.ceils[x][y].type === FREE ) {
                new Treasure( this, x, y, this.tileSize, this.tileSize );
                numcoins--;
            }
        }
    }

    createGnomes( numgnomes ) { //numgnomes:INT
        while( numgnomes > 0 ) {
            int x = rand()/1000000000 * this.columns;
            int y = rand()/1000000000 * this.rows;
            if( this.maze.ceils[x][y].type === FREE ) {
                new Gnome( this, x, y, this.tileSize, this.tileSize );
                numgnomes--;
            }
        }
    }

    createDragons( numdragons ) { //numdragons:INT
        while( numdragons > 0 ) {
            int x = rand()/1000000000 * this.columns;
            int y = rand()/1000000000 * this.rows;
            if( this.maze.ceils[x][y].type === FREE ) {
                new Dragon( this, x, y, this.tileSize, this.tileSize );
                numdragons--;
            }
        }
    }

    addWall( wall ) { //wall:Wall
        this.walls.push( wall );
    }

    drawWall( wall ) { //wall:Wall
        this.canvas.drawRect( wall.x * this.tileSize, wall.y * this.tileSize, this.tileSize, this.tileSize, 'black' );
    }

    // verifica si una entidad colisiona con alguna pared
    // bool
    checkCollisionPlayerWalls( player ) { //player:Player
        return !!this.walls.find( wall => {
            return player.x === wall.x && player.y === wall.y;
        })
    }

    gameOver( ) {
        alert("Has perdido!, se iniciara una nueva partida");
        this.init( );
    }

    update( ) {
        this.entities.forEach( entity => {
            entity.update( );
        })
    }

    render( ) {
        this.canvas.clear( );
        this.walls.forEach( wall => {
            this.drawWall( wall );
        })
        this.entities.forEach( entity => {
            entity.render( this.canvas );
        })
    }
}