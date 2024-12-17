Brick Breaker Game
A console-based Brick Breaker Game implemented in C++ using simple graphics and file handling. The game involves a player controlling a paddle to bounce a ball and break bricks arranged in layers, with each layer having a specific point value and color. This project also includes features for saving and loading game progress, as well as maintaining a high scores list.

Features
Gameplay Mechanics:

A paddle controlled by the player to bounce the ball.
Multiple layers of bricks with varying colors and points (3, 2, or 1 hits to break).
The ball bounces off walls, the paddle, and bricks to create dynamic gameplay.
Graphics:

Utilizes simple graphics functions for drawing bricks, paddle, ball, and game UI.
Color-coded bricks for different strength levels.
Save and Load Functionality:

Allows players to save their progress at any time using the s key.
Resume saved games or start a new game upon launching.
High Scores:

Automatically updates and maintains a high scores list with up to 5 entries.
Compares the current score with high scores and updates if applicable.
Keyboard Controls:

Left/Right Arrow Keys: Move the paddle.
p: Pause the game.
c: Resume the game from pause.
s: Save the current game state.
q: Quit the game.
Game Over Animation:

Displays a "GAME OVER" sequence when all lives are lost.
How It Works
Brick Layout:

Bricks are arranged in a 6x10 grid.
Top two rows: 3-hit bricks.
Middle two rows: 2-hit bricks.
Bottom two rows: 1-hit bricks.
Score Calculation:

Breaking a 3-hit brick: +20 points.
Breaking a 2-hit brick: +20 points.
Breaking a 1-hit brick: +50 points.
Lives:

The player starts with 3 lives.
Losing a life resets the ball position but maintains the current score and brick layout.
File Handling:

Save game state (brick layout, ball position, paddle position, score, lives, etc.) to gameSave.txt.
Retrieve high scores from highScores.txt and update them after the game ends.
Dependencies
This project uses a custom graphics library (yourgraphics.h) for drawing and rendering game elements. Ensure the library is properly included in your environment before compiling.

How to Run
Clone the repository or download the source code.
Compile the code using a C++ compiler.
bash
Copy code
g++ -o BrickBreaker BrickBreaker.cpp
Run the executable.
bash
Copy code
./BrickBreaker
Follow on-screen instructions to start a new game or load a saved game.
