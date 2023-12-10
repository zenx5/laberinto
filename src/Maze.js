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

class Maze {
    constructor( columns, rows ) { //columns:int, rows:int
        this.columns = columns;
        this.rows = rows;
        //aqui un array de arrays llamado ceils que contendra las casillas y que sera de dimenciones de las columnas y las filas
        this.ceils = Array.from( { length: rows }, () => Array.from( { length: columns }, () => new Ceil( FREE, 0, 0 ) ) );
        //ceils:Ceil[]
    }


    addCeil( type, x, y ) { // type:(wall, ....), x:int, y:int
        this.ceils[y][x] = new Ceil( type, x, y );
    }

    //Ceil[][]
    generate( ) {
        //colocamos el laberinto en un estado inicial de paredes y espacios libres intercalados
        for( let x = 0; x < this.columns; x++ ) {
            for( let y = 0; y < this.rows; y++ ) {
                if( x % 2 === 0 || y % 2 === 0 ) {
                    this.addCeil( WALL, x, y );
                }
                else {
                    this.addCeil( FREE, x, y );
                }
            }
        }
        this.ceils[1][1] = new Ceil( START, 1, 1 );
        this.ceils[this.rows-2][this.columns-2] = new Ceil( END, this.columns-2, this.rows-2 );

        //generamos el camino que une el inicio con el fin y las bifurcaciones
        this.addCeilToPath( this.ceils[1][1], null, this.ceils[this.rows-2][this.columns-2], 0 )

        return this.ceils;
    }

    addCeilToPath( currentCeil, from, to, i ) {  //currentCeil:Ceil, from:Ceil, to:Ceil, i:int
        // el parametro "i" es solo para debug
        //PREGUNTAR A MOISS SOBRE API INTEGRAR
        // console.log('iteracion',i)
        // console.log(this)
        if( currentCeil.belowToPath ) {
            // console.log('la celda actual ya pertenece al path o ya fue visitada')
            return;
        }
        currentCeil.belowToPath = true;
        
        let directions = ["up", "down", "left", "rigth"].sort( () => Math.random() - 0.5 );

        // console.log('va a entrar en las direcciones',directions)
        directions.forEach( direction => {
            // console.log(direction)
            let nextCeil = this.getNextCeil( currentCeil, direction );
            if( nextCeil && !nextCeil.belowToPath ) {
                // console.log('paso en la condicion de existencia de nextCeil')
                // nextCeil.belowToPath = true;
                nextCeil.from = currentCeil;

                //Hacer que la celda que esta entre currentCeil y nextCeil se marque como free
                this.addCeil( 'free', (currentCeil.x + nextCeil.x) / 2, (currentCeil.y + nextCeil.y) / 2 );
                // console.log(nextCeil, currentCeil, to)
                this.addCeilToPath( nextCeil, currentCeil, to, i+1 );
            }
        })
    }

    // return Ceil o null
    getNextCeil( currentCeil, direction ) { //currentCeil:Ceil, direction:int
        let x = currentCeil.x;
        let y = currentCeil.y;
        switch( direction ) {
            case 'up':
                y -= 2;
                break;

            case 'down':
                y += 2;
                break;

            case 'left':
                x -= 2;
                break;

            case 'rigth':
                x += 2;
                break;
        }
        if( this.pointBelowToBoard( x, y ) ) {
            return this.ceils[y][x];
        }
    }
    //Boolean
    pointBelowToBoard( x, y ) {
        return x >= 0 && x < this.columns && y >= 0 && y < this.rows;
    }

}
