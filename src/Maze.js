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
import { Canvas } from "./Canvas";
import { Wall } from "./Wall";

class Maze {
    constructor( width, height, container ) {
        let tileSize = 50;
        this.canvas = new Canvas( width*tileSize, height*tileSize, container );
        this.width = width;
        this.height = height;
        this.walls = [];
        this.entities = [];

    }

    addEntity( entity ) {
        this.entities.push( entity );
    }

    addWall( wall ) {
        this.walls.push( wall );
    }

    generate( ) {
        for ( let i = 0; i < this.width; i++ ) {
            for ( let j = 0; j < this.height; j++ ) {
                if ( i === 0 || j === 0 || i === this.width - 1 || j === this.height - 1 ) {
                    this.addWall( new Wall( i, j ) );
                    console.log(i,j)
                }
            }
            console.log("\n")
        }
    }
}
