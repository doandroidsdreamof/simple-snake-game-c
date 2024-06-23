### Project Structure

The project is organized into the following main components:

- **Main File (`snake.c`)**: Contains the main game loop, initialization, input handling, and game state management.
  
- **Linked List Implementation (`linkedList.c`, `linkedList.h`)**: Provides functionality to manage the snake's body as a linked list of nodes (`Node` structure).

- **Grid Drawing (`drawGrid.c`, `drawGrid.h`)**: Handles the drawing of the game grid using Raylib functions.

### Components

1. **Main Loop and Game State Management**:
   - **`snake.c`**: Controls the main game loop, initialization (`InitWindow`, `SetTargetFPS`), and game over conditions.
   - **`handleMovement()`**: Manages user input for controlling the snake's direction (`KEY_UP`, `KEY_DOWN`, `KEY_LEFT`, `KEY_RIGHT`).
   - **`updateGame(deltaTime)`**: Updates the game state based on elapsed time (`deltaTime`), including snake movement and collision detection.
   - **`drawGame()`**: Draws the game elements on the screen using Raylib (`DrawText`, `DrawRectangle`).

2. **Linked List Management**:
   - **`linkedList.h`**: Defines the `Node` structure and function prototypes for manipulating the linked list.
   - **`insertLinkedList()`**: Inserts new nodes (snake segments) into the linked list.
   - **`pushLinkedList()`**: Adds a new segment to the end of the snake.
   - **`resetLinkedList()`**: Frees memory allocated for the linked list upon game reset.

3. **Grid Drawing**:
   - **`drawGrid.h`**: Declares functions for drawing the game grid (`drawGrid()`).
   - **`drawGrid.c`**: Implements grid drawing using Raylib's `DrawLine` function.

### Dependencies

- **Raylib**: Graphics library used for rendering graphics and handling input.

### Installation

1. **Clone Repository**:
   ```bash
   git clone https://github.com/doandroidsdreamof/simple-snake-game-c.git
   cd snake-game

2. **Compile the Game**:
   ```bash
   Make
3. **Run the Game**:
   ```bash
   Make run