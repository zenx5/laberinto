const PLAYER_COLOR = "purple";

class Player extends Entity {
    constructor( game, x, y, width, height ) { // game:Game, x:int, y:int, width:int, height:int
        super( game, x, y, width, height );
        this.coins = 0;
    }

    update( ) {
        const { keyboard } = this.game

        // console.log(this.x < this.game.columns)
        // console.log('y',this.y, this.game.rows )

        if( keyboard.IsDown( keyboard.keys.RIGHT_ARROW ) && this.x < this.game.columns -1 ) {
            this.x++;
            if( this.game.checkCollisionPlayerWalls( this ) ) 
                this.x--;
        }
        if( keyboard.IsDown( keyboard.keys.LEFT_ARROW ) && this.x > 0 ) {
            this.x--;
            if( this.game.checkCollisionPlayerWalls( this ) ) 
                this.x++;
        }
        if( keyboard.IsDown( keyboard.keys.UP_ARROW ) && this.y > 0 ) {
            this.y--;
            if( this.game.checkCollisionPlayerWalls( this ) ) 
                this.y++;
        }
        if( keyboard.IsDown( keyboard.keys.DOWN_ARROW ) && this.y < this.game.rows -1 ) {
            this.y++;
            if( this.game.checkCollisionPlayerWalls( this ) )
                this.y--;
        }
        
        //comprovamos si en las casillas adyacentes hay alguna entidad con el metodo interactuar
        this.game.entities.forEach( entity => {
            if( 
                entity.y === this.y && (entity.x === this.x+1 || entity.x === this.x-1) ||
                entity.x === this.x && (entity.y === this.y+1 || entity.y === this.y-1) 
            ) {
                console.log("entro")
                entity.interactuar( this );
            }
        });

    }

    render( canvas ) {
        canvas.drawRect( this.x * this.game.tileSize, this.y * this.game.tileSize, this.width, this.height, PLAYER_COLOR );
    }

}
