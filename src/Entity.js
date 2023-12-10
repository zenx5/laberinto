class Entity {
    constructor( game, x, y, width, height ) { // game:Game, x:int, y:int, width:int, height:int
        this.game = game
        this.x = x
        this.y = y
        this.width = width
        this.height = height
        
        game.entities.push( this );
    }

    render( canvas ) {}
    update( ) {}
    interactuar( ) {}
}
