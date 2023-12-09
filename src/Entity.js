class Entity {
    constructor( game, x, y, width, height ) {
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