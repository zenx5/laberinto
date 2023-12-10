class Treasure extends Entity {
    constructor( game, x, y, width, height ) { // game:Game, x:int, y:int, width:int, height:int
      super( game, x, y, width, height );

      this.coins = Math.floor(Math.random() * 3) + 1;
    }

    update( ) {
        this.game.entities.find( entity => {
            if( entity instanceof Player && entity.x === this.x && entity.y === this.y ) {
                this.game.score++;
                this.game.entities.splice( this.game.entities.indexOf( this ), 1 );
                entity.coins += this.coins;
                alert(`Has conseguido un tesoto. ¡Has recolectado ${this.coins} monedas!, Ahora tienes ${entity.coins} monedas.`);
            }
        })
    }
  
    render(canvas) {
        // Lógica para renderizar el tesoro como un círculo amarillo en el canvas
        const radius = this.game.tileSize / 2; // Radio del círculo
        const centerX = (this.x + 0.5) * this.game.tileSize; // Coordenada x del centro
        const centerY = (this.y + 0.5) * this.game.tileSize; // Coordenada y del centro
        canvas.drawCircle(centerX, centerY, radius, 'yellow');
      }
  }
