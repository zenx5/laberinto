class Dragon : public Entity {
    int type = DRAGON;
    public:
        int requiredCoins = int coins = rand()/100000000; // Número de tesoros requeridos por el dragón
        // Dragon(game, x, y, width, height ) {
        //   super( game, x, y, width, height );
        // }

        void interactuar( Entity entity ) {
            // const mensaje = `¡Hola aventurero! Soy el dragón. Para pasar, necesitas darme ${this.requiredCoins} monedas.`;
            // alert(mensaje);

            if (entity.coins >= this->requiredCoins) {
                entity.coins -= this->requiredCoins;
                // alert(`¡Bien hecho! Has entregado ${this.requiredCoins} monedas al dragón. Puedes pasar. Te quedan ${entity.coins} monedas.`);
                // this.game.score += this.requiredCoins;
                this->kill();
            } else {
                // alert("¡El dragón te devoró! Necesitas más monedas para pasar.");
                this->game.gameOver( );
            }
        }

        void kill( void ) {
            // this->game.entities.splice( this->game.entities.indexOf( this ), 1 );
        }

        void render(Canvas canvas) {
            int color[3] = { 255, 0, 0 };
            canvas.drawRect(this->x * this->game.tileSize, this->y * this->game.tileSize, this->game.tileSize, this->game.tileSize, color);
        }
}