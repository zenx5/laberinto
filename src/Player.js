const PLAYER_COLOR = "purple";

class Player {
    constructor( game, x, y, width, height ) {
        this.game = game
        this.x = x
        this.y = y
        this.width = width
        this.height = height

        game.entities.push( this );
    }

    update( ) {
        const { keyboard } = this.game

        console.log( keyboard.IsDown( keyboard.keys.A ) )
        if( keyboard.IsDown( keyboard.keys.RIGHT_ARROW ) ) {
            this.x++;
        }
        if( keyboard.IsDown( keyboard.keys.LEFT_ARROW ) ) {
            this.x--;
        }
        if( keyboard.IsDown( keyboard.keys.UP_ARROW ) ) {
            this.y--;
        }
        if( keyboard.IsDown( keyboard.keys.DOWN_ARROW ) ) {
            this.y++;
        }
        console.log(this)
    }

    render( canvas ) {
        canvas.drawRect( this.x * this.game.tileSize, this.y * this.game.tileSize, this.width, this.height, PLAYER_COLOR );
    }

}