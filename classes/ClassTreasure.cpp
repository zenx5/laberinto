class Treasure : public Entity {
    int type = TREASURE;
    int coins = rand()/100000000;

    void update() {
        const size = GetSize( this->gama.entities );
        for( int i = 0; i<size; i++ ) {

            if( this->game.entities[ i ].type==ENTITY && this->x==this->game.entities[ i ].x && this->y==this->game.entities[ i ].y ){
                this->game.score++;
                //this->game.entities.splice( this.game.entities.indexOf( this ), 1 );
                this->game.entities[ i ].coins += this->coins;
            }
        }

        // .find( entity => {
        //     if( entity instanceof Player && entity.x === this.x && entity.y === this.y ) {
        //         this.game.score++;
        //         this.game.entities.splice( this.game.entities.indexOf( this ), 1 );
        //         entity.coins += this.coins;
        //         alert(`Has conseguido un tesoto. ¡Has recolectado ${this.coins} monedas!, Ahora tienes ${entity.coins} monedas.`);
        //     }
        // })
    }

    void render(Canvas canvas) {
        // Lógica para renderizar el tesoro como un círculo amarillo en el canvas
        float radius = this->game.tileSize / 2; // Radio del círculo
        int centerX = (this->x + 10) * this->game.tileSize; // Coordenada x del centro
        int centerY = (this->y + 10) * this->game.tileSize; // Coordenada y del centro
        int color[3] = { 255, 255, 0};
        canvas.drawCircle(centerX, centerY, radius, color);
      }
  }