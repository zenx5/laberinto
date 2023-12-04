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
// import { Canvas } from "./Canvas";
// import { Wall } from "./Wall";

class Maze {
    constructor( columns, rows, container ) {
        let tileSize = 50;
        this.columns = columns;
        this.rows = rows;
        this.height = columns*tileSize;
        this.width = rows*tileSize;
        this.canvas = new Canvas( this.width, this.height, container );
        this.walls = [];
        this.entities = [];
        //aqui un array de arrays llamado ceils que contendra las casillas y que sera de dimenciones de las columnas y las filas
        this.ceils = Array.from( { length: rows }, () => Array.from( { length: columns }, () => new Ceil( 'free', 0, 0 ) ) );
        console.log(this)
    }

    addEntity( entity ) {
        this.entities.push( entity );
    }


    addCeil( type, x, y ) {
        this.ceils[y][x] = new Ceil( type, x, y );
    }

    generate( ) {
        //colocamos el laberinto en un estado inicial de paredes y espacios libres intercalados
        for( let x = 0; x < this.columns; x++ ) {
            for( let y = 0; y < this.rows; y++ ) {
                if( x % 2 === 0 || y % 2 === 0 ) {
                    this.addCeil( 'wall', x, y );
                }
                else {
                    this.addCeil( 'free', x, y );
                }
            }
        }
        this.ceils[1][1] = new Ceil( 'init', 1, 1 );
        this.ceils[this.rows-2][this.columns-2] = new Ceil( 'end' );

    }

    render( ) {

    }
}
