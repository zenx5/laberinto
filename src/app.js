// import { Maze } from './Maze'

let maze = new Maze( 41, 41, 'root' );
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