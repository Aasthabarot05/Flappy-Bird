# 🐦 Flappy Bird Console Game in C++

This project is a **console-based recreation of the classic Flappy Bird game**, written in C++ using simple character graphics (ASCII art). It uses `windows.h` and console manipulation functions to animate the bird and pipes.

---

## 📌 Overview

In this game, the player controls a small bird represented by characters on the console. The goal is to keep the bird flying by pressing the **spacebar**, avoiding vertical pipes that scroll toward the player.

- ⬆️ Press **Spacebar** to make the bird jump.
- 💥 Avoid hitting pipes or the ground.
- 🧮 Score increases with every pipe passed.
- 📏 Pipes are randomly generated.
- 🖥️ Fully rendered in the **Windows console**.

---

## ⚙️ Requirements

| Requirement      | Description                     |
|------------------|---------------------------------|
| OS               | Windows (due to use of `windows.h`) |
| Compiler         | g++, MinGW, or Turbo C++         |
| Language         | C++ (with support for `windows.h`) |
| Terminal         | CMD or any compatible terminal   |

---

## 📦 Main Data Structures

| Data Structure      | Usage                                 |
|---------------------|----------------------------------------|
| `char bird[2][6]`   | 2D character array representing bird sprite |
| `int pipePos[3]`    | X-positions of pipes                   |
| `int gapPos[3]`     | Y-positions of the gap in the pipe     |
| `int pipeFlag[3]`   | Track if the pipe is active or not     |
| `COORD`             | Struct to move cursor position on console |
| `HANDLE console`    | Console output handle (for cursor control) |

---

## 🧠 Key Programming Concepts Used

- **Procedural Programming** (everything is function-based)
- **Random number generation** (`rand()` and `srand()`)
- **Console graphics using `gotoxy()`**
- **Event-driven input handling** using `kbhit()` and `getch()`
- **ASCII art rendering**
- **Game Loop & Frame Control** (`Sleep()` for delay)

---

## 💡 Main Functional Flow (`main()`)

```cpp
int main() {
    setcursor(0,0);  // Hide the console cursor
    srand((unsigned)time(NULL));  // Seed RNG

    do {
        system("cls");  // Clear screen
        // Display menu UI
        gotoxy(10,5); cout<<" -------------------------- "; 
        gotoxy(10,6); cout<<" |      Flappy Bird       | "; 
        gotoxy(10,7); cout<<" --------------------------";
        gotoxy(10,9); cout<<"1. Start Game";
        gotoxy(10,10); cout<<"2. Instructions";     
        gotoxy(10,11); cout<<"3. Quit";
        gotoxy(10,13); cout<<"Select option: ";
        
        char op = getche();  // Wait for user input
        if(op == '1') play();           // Start the game
        else if(op == '2') instructions(); // Show how to play
        else if(op == '3') exit(0);     // Exit game

    } while(1);

    return 0;
}

