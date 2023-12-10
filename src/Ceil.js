class Ceil {
    constructor( type, x, y ) { // type:(free, wall, init, end), x:int, y:int
        this.x = x
        this.y = y
        this.type = type // free, wall, init, end
        this.belowToPath = false // belowToPath:bool
        this.from = null; // from:Ceil
    }

    setType( type ) { //type:(free, wall, init, end)
        this.type = type
    }
}
