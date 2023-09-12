# Emptying-parking-lot-game
In this project we are given as input, a M*N grid that represents a parking lot.Inside the parking lot there may
be cars that face the north or the south,cars that face the east or the west and obstacles with no specific direction. 
![grid](https://github.com/AnestisZotos/Emptying-parking-lot-game/assets/123301659/eec4646e-89ee-42ef-b9f5-b635f573a984)
We can move the cars from a cell to another cell of the grid or even take them out of the parking lot, but there
are some prerequisites:We can move a car to another cell only if the destination cell is empty and the direction of the
car allows the movement(car with direction n/s can move up or down and car with direction w/e can move right or left) .
The goal is to find the right moves in order to empty the parking lot from cars.To solve this problem i modeled the parking lot
as a class and then run BFS to find the minimum number of moves that must be done in order to empty the parking.
