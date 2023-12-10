const QUESTIONS = [
    {
        question: '¿Cuánto es 2 + 2?',
        answer: '4'
    },
    {
        question: '¿Cuánto es 3 + 3?',
        answer: '6'
    },
    {
        question: 'En que pais se encuentra el salto angel?',
        answer: 'Venezuela'
    },
    {
        question: 'Cuantos dias tiene un año?',
        answer: '365'
    },
    {
        question: 'Cual es el mes mas corto?',
        answer: 'febrero'
    },
    {
        question: 'Cual es el planeta mas caliente?',
        answer: 'venus'
    }
]

class Gnome extends Entity {
    constructor( game, x, y, width, height ) { //game:Game, x:int, y:int, width:int, height:int
        super( game, x, y, width, height );

        this.questions = QUESTIONS; // questions:Question[]
    }

    ask( ) {
        const index = Math.floor(Math.random() * this.questions.length);
        return this.questions[index];
    }
  
    interactuar(jugador) {
        alert("¡Hola aventurero! Soy el gnomo. Te haré una pregunta.");
        const { question, answer } = this.ask();

        const userAnswer = prompt( question );
    
        if( userAnswer === answer ) {
            alert("¡Respuesta correcta! Recibes un tesoro.");
            new Treasure( this.game, this.x, this.y, this.game.tileSize, this.game.tileSize );
        } else {
            alert("Respuesta incorrecta. El gnomo se va.");
        }
        this.kill( );
    }

    kill( ) {
        this.game.entities.splice( this.game.entities.indexOf( this ), 1 );
    }
  
    render(canvas) {
      // Lógica para renderizar el gnomo en el canvas
      canvas.drawRect(this.x * this.game.tileSize, this.y * this.game.tileSize, this.game.tileSize, this.game.tileSize, 'green');
    }
  }
  
