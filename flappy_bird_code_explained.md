# 🎮 Flappy Bird Console Game in C++ 🐤

This is a simple and fun **console-based version** of the classic **Flappy Bird** game, created using **C++**. The game runs in a **text-based console environment**, where the player controls a bird 🐤 that must navigate through 🌵 **pipes** without colliding.

The game is easy to play, lightweight, and a great starting point to explore **basic game development** with C++. It uses simple concepts like **game loops**, **keyboard inputs**, **collision detection**, and **ASCII/emoji-based rendering** to simulate a visually fun and interactive game.

---

## 📸 Game Screenshots

1. **Main Menu Screen**  
   ![Main Menu](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gamestart.png)

2. **Gameplay Screen**  
   ![Gameplay](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameplayarea.png)

3. **Game Over Screen**  
   ![Game Over](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameover.png)

4. **Instructions Screen**  
   ![Instructions](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/gameinstruction.png)

---

## 🧩 Table of Contents

- [🚀 Project Overview](#project-overview)
- [✨ Features](#features)
- [⚙️ How It Works](#how-it-works)
- [🧱 Data Structures Used](#data-structures-used)
- [🔁 Game Flow](#game-flow)
- [💡 Main Functions of the Game](#main-functions-of-the-game-)
- [🆕 New Features and Enhancements](#new-features-and-changes-in-the-game-modified-by-me-)
- [🛠️ Installation](#installation)
- [🎯 Usage](#usage)
- [📜 License](#license)

---

## 🚀 Project Overview

This is a **console-based version** of the famous 🐦 Flappy Bird game written in **C++** using **ASCII characters and emojis**. The objective is to guide the bird through gaps in pipes and avoid crashing into the walls or ground. The longer you survive, the higher your score! 📈

---

## ✨ Features

- 🐤 **Bird Movement:** Control the bird with the **Spacebar** to fly, while gravity pulls it downward.
- 🌵 **Random Pipe Generation:** Pipes are created at different vertical positions with a gap to fly through.
- 📈 **Live Score Tracking:** Your score increases every time you pass a pipe. Displayed in real time!
- 💥 **Collision Detection:** The game ends if the bird crashes into a pipe or the ground.
- 📚 **Instructions Screen:** Explains controls and how to play the game.
- 🕹️ **Interactive Menu:** Choose to start the game, read instructions, or exit.
- 🎨 **Emoji Visuals:** Makes gameplay visually fun with emoji-based graphics.
- 🧱 **Console Borders:** Drawn using emojis to better separate the play area.
  
---

## ⚙️ How It Works

### 🛠️ 1. Console Setup

- The `gotoxy()` function is used to position elements using `SetConsoleCursorPosition()`.
- The bird, pipes, and borders are drawn using ASCII/emoji characters.

### 🔁 2. Game Loop (`play()`)

Each loop iteration performs:
- ⌨️ Handling key input (Spacebar to fly, Esc to quit)
- 🦅 Drawing & erasing the bird
- 🌵 Drawing & erasing pipes
- ⚠️ Detecting collisions
- 📈 Updating score
- 💤 Adding a small delay for animation (`Sleep(100)`)

### 🎮 3. Game Over

- When a collision is detected, the `gameover()` function is triggered.
- Shows a final score and prompts user to return to menu.

### 🧱 4. Pipe Generation

- `genPipe()` randomly sets pipe gap positions.
- Pipes are moved frame-by-frame, looping across the screen endlessly.

### ⚡ 5. Collision Detection

- The `collision()` function checks whether the bird collides with pipes or hits the ground.

### 📚 6. Instructions

- A detailed instruction screen is available from the main menu.

---

## 🧱 Data Structures Used

- **Arrays:**
  - `pipePos[3]`: X-positions of pipes
  - `gapPos[3]`: Y-positions of gaps
  - `pipeFlag[3]`: Tracks active pipes

- **2D Array:**
  - `string bird[2][6]`: Represents the bird’s ASCII/emoji art

- **Variables:**
  - `int birdPos`: Vertical position of the bird
  - `int score`: Player’s score

---

## 🔁 Game Flow

1. Start at the **Main Menu**
2. Press **1** to Play, **2** for Instructions, **3** to Quit
3. Use **Spacebar** to flap and fly
4. Avoid hitting pipes or floor/ceiling
5. Game Over screen shows final score
6. Return to main menu to play again

---

## 💡 Main Functions of the Game 🚀

### 1. `main()` 🏁
- Starts the game
- Displays main menu
- Handles user input to start game/instructions/quit

### 2. `play()` 🎮
- Main game loop
- Updates bird & pipe positions
- Handles input, collisions, and scoring

### 3. `gotoxy(x, y)` 🎯
- Moves console cursor to specified `(x, y)` for drawing

### 4. `drawBorder()` 🧱
- Draws the top, bottom, and side borders using emoji bricks

### 5. `genPipe(ind)` 🌿
- Sets random pipe gap at index `ind`

### 6. `drawPipe(ind)` & `erasePipe(ind)` 🌵❌
- Draws or clears pipe using gap positions

### 7. `drawBird()` & `eraseBird()` 🐤🕊️
- Draws or erases the bird on screen at its position

### 8. `collision()` ⚡
- Checks if bird hits pipe or ground

### 9. `gameover()` 💥
- Displays game over message & prompts restart

### 10. `updateScore()` 💯
- Shows the current score on screen

### 11. `instructions()` 📖
- Displays how-to-play screen with controls

---

## 🆕 New Features and Changes in the Game Modified by Me 🚀

### ✨ 1. **Emoji-based Visuals**
- 🐤 for the bird  
- 🌵 for pipes  
- 🧱 for walls  
- 📈 for score
-  ![Main Menu](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uistartscreen.png)

### 🧱 2. **Game Area Borders**
- Now clearly drawn using 🧱 to make the game feel structured
  ![Gameplay](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uigameboard.png)
### 📚 3. **Updated Instructions**
- Clearer instructions with emojis to enhance readability  
  ![Instructions](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uiinstruction.png)

### 📈 4. **Live Scoreboard**
- Updated design to include 📈 emoji and real-time tracking

### ⚡ 5. **Improved Collision System**
- More responsive detection of pipe and floor hits

### 🕹️ 6. **Keyboard Controls**
- ⬆️ SPACE = Jump  
- ⎋ ESC = Quit  

### 💥 7. **Game Over Screen**
- Displays score and gives option to restart  
  ![Game Over](https://github.com/Aasthabarot05/Flappy-Bird/blob/main/Screenshots/uigameover.png)

---
## 🔮 Future Plans

- Add sound effects for flaps, points, and game over
- Implement difficulty levels (speed increase)
- High score saving across sessions
- Bird skin customization 🎨
- Multiplayer mode (crazy idea but fun!)
## 🛠️ Installation

1. 📥 Clone or download the repository
2. 🧰 Make sure you have a C++ compiler installed (e.g., `g++`)
3. 🔨 Compile the code:
   ```bash
   g++ -o flappybird flappybird.cpp
