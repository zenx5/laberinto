class Dragon extends Entity {
    constructor(game, x, y, width, height ) {
      super( game, x, y, width, height );

      this.requiredCoins = Math.floor(Math.random() * 2) + 1; // Número de tesoros requeridos por el dragón
    }
  
    interactuar( entity ) {
        const mensaje = `¡Hola aventurero! Soy el dragón. Para pasar, necesitas darme ${this.requiredCoins} monedas.`;
        alert(mensaje);
    
        if (entity.coins >= this.requiredCoins) {
            entity.coins -= this.requiredCoins;
            alert(`¡Bien hecho! Has entregado ${this.requiredCoins} monedas al dragón. Puedes pasar. Te quedan ${entity.coins} monedas.`);
            // this.game.score += this.requiredCoins;
            this.kill( );
        } else {
            alert("¡El dragón te devoró! Necesitas más monedas para pasar.");
            this.game.gameOver( );
        }
    }

    kill( ) {
        this.game.entities.splice( this.game.entities.indexOf( this ), 1 );
    }
  
    render(canvas) {
        // Lógica para renderizar el dragón en el canvas
        canvas.drawRect(this.x * this.game.tileSize, this.y * this.game.tileSize, this.game.tileSize, this.game.tileSize, 'red');
    }
  }
  