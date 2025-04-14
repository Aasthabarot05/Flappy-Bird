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

## 🧠 Other Data Structures & Key Concepts Used

This project incorporates a mix of fundamental **data structures** and **programming concepts** to deliver a smooth, interactive gaming experience in a console window. Below is a breakdown:

---

### 📦 Arrays

- **1D Arrays**
  - `int pipePos[3];` → Stores the horizontal positions of up to 3 pipes
  - `int gapPos[3];` → Stores the vertical gap position for each pipe
  - `int pipeFlag[3];` → Keeps track of whether each pipe is active or not (boolean-like behavior using `int`)

- **2D Array**
  - `string bird[2][6];` → Used to visually render the bird with emojis and ASCII characters in a 2-row, 6-column layout

✅ Arrays are central to managing **multiple pipe objects** and drawing the **bird sprite** dynamically.

---

### ⏱️ Game Loop & Real-Time Updates

- The game uses a **real-time loop** inside the `play()` function.
- Continuously checks for user input with `kbhit()` and updates the game state every few milliseconds using `Sleep(100);`
- This ensures the **bird moves**, **pipes scroll**, and **collision detection** works smoothly.

---

### 🎯 Cursor Control & Graphics Simulation

- **`gotoxy(x, y)`** is used throughout the game to move the console cursor for drawing and erasing game elements.
- This simulates graphics in a **text-based environment** by updating specific positions of the console screen.

---

### ⚠️ Collision Detection

- Implemented through logical comparisons:
  - If the bird's Y-position is **outside the pipe gap** when it reaches a pipe → Collision!
  - If the bird **falls below the screen** → Game Over!
- All done using simple **if-statements**, making it efficient and lightweight.

---

### 🔄 Modular Design

Each functionality is broken into modular functions, such as:
- `drawPipe()`, `erasePipe()` → Pipe management 🌵
- `drawBird()`, `eraseBird()` → Bird animation 🐤
- `collision()` → Collision checking 💥
- `updateScore()` → Real-time scoring 📈
- `gameover()` → Game over screen handler

✅ This modularity makes the code easier to read, debug, and enhance.

---

### 🔐 Control Structures Used

- **Loops:**
  - `for` loops → Used for drawing borders, pipes, and bird
  - `while` loop → Game loop for real-time updates

- **Conditionals:**
  - `if`, `else if`, and nested `if` blocks for handling input, collisions, and pipe logic

---

### 🧮 Randomness

- **`rand()`** is used in `genPipe()` to generate random positions for pipe gaps, adding **variety and unpredictability** to the gameplay.

---

### 🧑‍💻 Windows API Concepts

- **Cursor Visibility & Positioning** → via `SetConsoleCursorPosition` and `SetConsoleCursorInfo`
- These functions are key to manipulating the console screen like a canvas 🎨

---

> 📝 **In Summary:**  
This game uses a mix of **arrays**, **modular functions**, **game loop architecture**, **cursor manipulation**, and **Windows console API** to replicate an interactive game using only C++ and text-based graphics.

## 🔁 Game Flow

1. Start at the **Main Menu**
2. Press **1** to Play,
    **2** for Instructions,
    **3** to Quit
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
## 🎓 Learning Outcomes

By building this Flappy Bird game in C++, I gained hands-on experience and improved my understanding of several core programming and game development concepts:

### 🧠 Core Concepts Learned

- **Game Loops** ⏳  
  Learned how to create and manage a continuous loop that updates game elements in real-time.

- **Real-Time User Input** ⌨️  
  Understood how to handle keyboard inputs dynamically using functions like `kbhit()` and `getch()`.

- **Console Graphics with ASCII & Emojis** 🎨  
  Discovered how to use ASCII characters and emojis creatively to design UI elements in a text-based console window.

- **Collision Detection** ⚠️  
  Implemented simple logic to detect interactions between the bird and pipes/ground.

- **Randomization** 🎲  
  Used the `rand()` function to generate random gap positions for pipes, introducing unpredictability.

- **Cursor Control in Console** 🎯  
  Used Windows-specific console functions like `SetConsoleCursorPosition()` for precise drawing in the terminal.

- **Functions & Code Modularity** 🧩  
  Broke the game into smaller, manageable functions to make the code more modular, readable, and reusable.

- **Score Tracking & UI Update** 📈  
  Created a live scoreboard system to display and update the player's progress in real-time.

- **Structuring a Console Game Project** 🗂️  
  Learned how to structure, document, and organize code for a fun and functional C++ game project.

- **Creative Thinking** 🌈  
  Experimented with emojis to make the console UI more engaging and user-friendly.

---

> 🔁 This project helped me bridge theory and practice by applying C++ concepts in a fun and interactive way. It also opened the door to exploring more advanced areas of game development. 🚀

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
