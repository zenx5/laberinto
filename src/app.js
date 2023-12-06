/*Juego de Laberinto donde con el paradigma de POO
Hay un laberinto conformado por mazmorras. Hay una entrada (marcada en azul) y una salida (marcada en rojo). El jugador intenta ir de la entrada a la salida del laberinto. Cada casilla del laberinto puede ser:
• Una pared (negro).
• Un gnomo (verde) que te hará una pregunta que tienes que contestar. Si aciertas en la respuesta entonces desaparece y te dejará pasar. Además, te dejará un tesoro en la casilla donde él estaba.
• Un tesoro (una moneda amarilla). Puedes tomarla, si lo deseas. Ayudaran a salvar al jugador del dragón.
• Un dragón (rojo). El dragón acabará con el jugador si se aparece, la manera que te deje libre es que el jugador le entregue el número de tesoros que él te diga.
• El jugador (Morado). Este se moverá con los comandos del mouse.
• El resto de las casillas están vacías (son blancas).
Debe llevar estadísticas (score) de los jugadores.
La lógica del juego debe implementarse por medio de estas clases:
• Laberinto: un espacio rectangular de un tamaño a elegir por el usuario. En cada casilla debe haber un puntero que apunta a alguno de estos objetos. Si el puntero es nulo, la casilla está vacía.
• Gnomo: un ser que te hace preguntas extrañas cuando estás en una casilla adyacente. Si aciertas, te dará un tesoro y desaparecerá.
• Dragón: si entras en su casilla te devorará, a no ser que le entregues suficientes tesoros. El número de tesoros requerido te lo dice justo cuando estés en una casilla adyacente.
• Tesoro: un objeto que hay que recoger para contentar a los dragones. Para coger un tesoro basta por pasar por la casilla donde está. Estas serán colocadas en forma aleatoria.
• Jugador: El personaje del juego. Puede ir en 4 direcciones, tomar tesoros, entregar tesoros y responder preguntas.
*/
const FREE = 0;
const WALL = 1;
const START = 2;
const END = 3;

class Game {
    constructor( columns, rows, container ) {
        this.maze = new Maze( columns, rows );
        this.tileSize = 15;
        this.height = columns * this.tileSize;
        this.width = rows * this.tileSize;
        this.canvas = new Canvas( this.width, this.height, container );
        this.walls = [];
        this.entities = [];

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
        new Player( this );

        this.render( )
    }

    addWall( wall ) {
        this.walls.push( wall );
    }

    drawWall( wall ) {
        this.canvas.drawRect( wall.x * this.tileSize, wall.y * this.tileSize, this.tileSize, this.tileSize, 'black' );
    }

    update( ) {
        this.entities.forEach( entity => {
            entity.update( );
        })
    }

    render( ) {
        this.walls.forEach( wall => {
            this.drawWall( wall );
        })
        this.entities.forEach( entity => {
            entity.render( this.canvas.context );
        })
    }
}

new Game( 47, 47, 'root' )