class Ceil {
    constructor( type, x, y ) {
        this.x = x
        this.y = y
        this.type = type // free, wall, init, end
        this.belowToPath = false
        this.from = null;
    }

    setType( type ) {
        this.type = type
    }
}