# Flappy Bird Console Game in C++

This is a simple and fun console-based version of the classic **Flappy Bird** game, created using **C++**. The game is played in a text-based environment, where the player controls a bird that must navigate through columns of pipes without colliding with them. The bird can "jump" by pressing the spacebar and falls due to gravity when no input is provided. The goal is to keep the bird alive for as long as possible by passing through the gaps in the pipes while avoiding collisions with them.

This project is a great example of creating interactive games in a console window, using basic concepts like game loops, keyboard inputs, collision detection, and real-time rendering of text-based graphics.

This game runs in the console/terminal and is designed to be simple, easy to play, and a fun way to learn about basic game development in C++.
## Game Screenshots

Here are some screenshots of the game:

1. **Main Menu Screen:**
   ![Main Menu](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gamestart.png)
      ![Main Menu](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uistartscreen.png)


2. **Gameplay:**
   ![Gameplay](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameplayarea.png)
      ![Gameplay](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uigameboard.png)

3. **Game Over Screen:**
   ![Game Over](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameover.png)
    ![Game Over](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uigameover.png)
4. **Game instructions:**
      ![Game instruction](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameinstruction.png)
   ![Game instruction](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uiinstruction.png)
   # Flappy Bird Game in C++

## Project Overview

This is a console-based implementation of the famous **Flappy Bird** game written in C++. The game is designed to be played in the command prompt using ASCII-based graphics. The objective is to control a bird, make it fly through gaps in pipes, and avoid collisions with the pipes or the ground. The game continues until the bird hits a pipe or the ground.

## Table of Contents

- [Features](#features)
- [How It Works](#how-it-works)
- [Data Structures](#data-structures-used)
- [Game Flow](#game-flow)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Features

- **Graphical Display:**  
  The game uses ASCII characters to render the bird, pipes, and game borders on the console screen.

- **Bird Movement:**  
  The bird moves based on the player's input. The player can make the bird "fly" by pressing the **Spacebar**, which makes the bird rise temporarily. The bird falls continuously due to gravity unless the spacebar is pressed.

- **Pipe Generation and Movement:**  
  Pipes are generated at random vertical positions and move from right to left across the screen. A gap exists in the middle of the pipes through which the bird must pass.

- **Score System:**  
  The player earns points every time the bird successfully passes through a gap in the pipes. The score is displayed in real-time.

- **Game Over and Restart:**  
  If the bird collides with a pipe or the ground, the game ends, and a "Game Over" screen is displayed. The player can restart the game by pressing any key.

- **Instructions:**  
  The game includes a screen that explains the basic controls, such as pressing the spacebar to make the bird fly.

- **Main Menu:**  
  The game starts with a main menu that allows the user to start the game, view instructions, or quit.

## How It Works

### 1. Setting Up the Console

The program sets up the console window for proper rendering of the game's graphical elements using ASCII characters. The `gotoxy()` function positions the cursor in the console window to draw the bird, pipes, and game borders at the right locations.

### 2. Main Game Loop

The core of the game lies in the main loop inside the `play()` function. This loop continues until the player quits or a collision occurs. Each iteration performs the following:

- **User Input Handling:**  
  The program checks if the player presses a key using `kbhit()` and `getch()`. If the spacebar is pressed, the bird rises; otherwise, gravity pulls the bird downward.

- **Drawing Game Elements:**  
  The bird and pipes are drawn using ASCII characters. The bird’s position is updated every frame.

- **Pipe Movement:**  
  The pipes move from right to left across the screen. Once a pipe goes off-screen, it is reset to the right side, creating an endless stream of pipes.

- **Collision Detection:**  
  The program checks if the bird collides with a pipe or falls below the screen. If a collision is detected, the game ends.

- **Score Update:**  
  The score is updated each time the bird successfully passes through a pipe. The score is displayed and updated in real-time.

- **Smooth Animation:**  
  A delay (`Sleep(100)`) is introduced to ensure smooth animation and to allow the player to see the game elements update.

### 3. Game Over and Restart

When a collision is detected (either the bird hits a pipe or the ground), the `gameover()` function is called, which displays a "Game Over" message. The player can press any key to return to the main menu and restart the game.

### 4. Main Menu

The game begins with a main menu that gives the player three options:
- **Start the game**: Begin a new game.
- **View instructions**: Display instructions on how to play.
- **Quit**: Exit the game.

The player interacts with the menu by pressing the corresponding number.

### 5. Pipe Generation and Gap Creation

Pipes are randomly generated with a vertical gap in the middle. The `genPipe()` function sets the gap position, ensuring that the bird can pass through without hitting the pipes. Pipes are redrawn every frame, and once a pipe moves off-screen, it is recycled and reappears on the right side.

### 6. Collision Detection

The `collision()` function checks if the bird's current position intersects with the pipes. If the bird is outside the gap or hits a pipe, the function returns `1`, signaling a collision.

### 7. Bird Movement

The bird's position (`birdPos`) is updated each frame. The spacebar makes the bird move upward, while gravity continuously pulls it downward. The bird's vertical movement is confined within the screen bounds to prevent it from moving off-screen.

### 8. Score and Game State

The score increments each time the bird successfully passes a pipe. The score is updated and displayed on the screen in real-time using the `updateScore()` function.

## Data Structures Used

- **Arrays:**
  - `pipePos[3]`: Holds the x-coordinates of the pipes.
  - `gapPos[3]`: Holds the y-coordinate (vertical position) of the gaps in the pipes.
  - `pipeFlag[3]`: Flags indicating whether a pipe is currently active (visible).

- **2D Array:**
  - `char bird[2][6]`: This array defines the bird’s appearance using ASCII characters. Each element represents a part of the bird.

- **Variables:**
  - `birdPos`: Tracks the bird's current vertical position.
  - `score`: Tracks the current score of the game.

## Game Flow

1. **Main Menu**: The user selects an option (Start Game, Instructions, Quit).
2. **Start Game**: The game begins, and the bird moves based on the user input.
3. **Game Loop**: The game continues until the bird collides with a pipe or the ground.
4. **Game Over**: Once the game ends, the player is prompted to return to the main menu.

## Installation

1. Clone this repository or download the source code.
2. Ensure you have a C++ compiler installed (e.g., [GCC](https://gcc.gnu.org/)).
3. Compile the code using the following command (in the terminal/command prompt):
    ```bash
    g++ -o flappybird flappybird.cpp
    ```
4. Run the game:
    ```bash
    ./flappybird
    ```

## Usage

- Press the **Spacebar** to make the bird fly.
- The bird continuously falls unless you press the spacebar.
- Avoid colliding with pipes or the ground to keep playing.
- Press **Esc** to quit the game.





