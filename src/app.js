
let maze = new Maze( 47, 47, 'root' );
let ceils = maze.generate( )
ceils.forEach( rows => {
    rows.forEach( ceil => {
        if( ceil.type === 'wall' ) {
            let wall = new Wall( maze, ceil.x, ceil.y );
            maze.addWall( wall );
        }
    })
})
maze.render( )
console.log('rendered')