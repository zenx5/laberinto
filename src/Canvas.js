class Canvas {
    constructor(width, height, container) {
        var canvas = document.getElementById(container||'canvas')
        var context = canvas.getContext('2d')

        canvas.style.border = '1px solid black'
        canvas.width = Math.round( width )
        canvas.height = Math.round( height )
        this.canvas = canvas
        this.context = context
    }

    drawRect(x, y, w, h, color='black') {
        this.context.fillStyle = color
        this.context.fillRect(x, y, w, h)
    }

    drawCircle(x, y, radius, color='black') {
        this.context.fillStyle = color
        this.context.beginPath( )
        this.context.arc( x, y, radius, 0, 2 * Math.PI, false )
        this.context.fill( )
    }

    clear( ) {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height)
    }
}