# TBSGame
A demo application implementing turn based mechanics on a square grid world.

## Specs
To ensure not stepping on ones own toe - start simple, make it work, encapsulate and continue.
### Phase 1
When all points are fullfilled, the player should be able to control objects in a square grid world by selecting with left click and moving to a different tile with right clicking.
* The world is represented by tiles on a square grid and the objects located in this world. This is the tilemap.
  * The tilemap shall be associated with a graph representing the cost of moving from on tile to another.
  * Each tile is the neighbour of all four adjacent tiles in the graph representation.
  * The weight of each tile shall be selected randomly on construction and be visually represented.
  * Tiles shall be selectable and give visual feedback by mouse clicks.
  * Tiles shall respond to having the mouse hovering over them and give visual feedback.
* The world shall contain several objects under player control.
  * The base visual for the object should be a specific colour on the map, visually distinct from the rest.
  * Each object can be individually selected and give visual feedback on this.
  * Selected object shall be controllable by right clicking on a target tile. THe selected object shall move sequentially (in real time, not logical time) along the fastest route.
  * Before clicking to move, the fastest path should be precalculated and visually represented on the map. Using the precalculatedGraphCosts method in preppers, showing fastest paths from object to mouseover target will be fast.
* Event handling should be done on a listener/eventmanager pattern
  * The tilemap and objects shall not independently perform the logic of coloring the tilemap
  * Each object shall have a limited amount of moves per turn. This should be captured by a turn resolver,
* The turn is resolved by a class that stores the base position of objects at the start of the turn, and when a move is made, store the new position. The turn resolver shall prevent moves that exceed allowed moves.

* All preceding points shall be encapsulated by appropriate classes and be invisible from the point of view of the main function.

#### Implementation
* Graphical and logical tilemap separated.

Distinction between logical and world coordinates:
* The logical position is an integer 2-uple that corresponds to a certain tile. There is a one-to-one pair relation between coordinate-tilemap and coordinate-graph.
* Graph, tilemap and objects should be encapsulated within a class. World events should be generated at this level and passed to appropriate elements. Input events are passed to this class, but generated outside.
* Graphnodes and objects should be easily accessed using coordinates.
  * Using the tilmapgraph in preppers should be good
  * Objects should be stored in an appropriate data structure.
    * Map is log(N)
    * 2DArray is constant lookup