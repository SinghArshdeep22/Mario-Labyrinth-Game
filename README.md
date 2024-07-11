# Mario-Labyrinth-Game
The maze game was developed in C++ using the Allegro library, an open-source graphics library designed for the creation of games. The code includes several functions to manage character movement, coin collection and the prevention of invalid movements within the maze. The main components and functions of the game are described below:

## Graphic and Audio Setup:
- The game uses various bitmaps to represent the character, coins, exit door and background.
- The Allegro sound module is used to include sound effects such as the coin collection and victory sound.

## Screen Size:
- The screen size is set to 1696x1040 pixels, thus fitting a game grid of 16x10.

## Character Movement:

- Character movement is handled by specific functions that allow the character to move within the maze and prevent movement through walls.
- Functions such as prevent_movement_top, prevent_movement_left, prevent_movement_right and prevent_movement_bottom handle collisions with the edges of the maze.

## Coin Collection:
- Coins are scattered within the maze and must be collected to increase the score.
- The coin_collection function handles the logic of coin collection.
  
## Victory Messages:
- Once all coins have been collected and the exit has been reached, a victory message is displayed using the won_message function.

## Menu and User Interface:
- The game includes an initial menu managed by the menu function, which allows the player to start a new game or exit the game.

# Conclusion
This maze game offers an immersive experience thanks to the integration of graphic and sound elements via the Allegro library. The implemented features make for an interesting adventure in which the player must navigate through the maze, collect all the coins and achieve victory.
