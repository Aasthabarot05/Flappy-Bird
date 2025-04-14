# 🐦 Flappy Bird Console Game (C++) - Full Line-by-Line Explanation

This document provides a **complete breakdown** of a Flappy Bird-style game made in C++ for the Windows console. It explains what each line does and how the code works behind the scenes.

---

## 📦 Headers & Libraries

```cpp
#include<iostream>
Provides input/output functions like cout and cin.

cpp
Copy
Edit
#include<conio.h>
Used for functions like getch() and kbhit(), which help detect keypresses without Enter. (Windows-only)

cpp
Copy
Edit
#include<dos.h>
An old header, sometimes needed for Sleep() in Turbo C++ compilers. Modern compilers typically use windows.h.

cpp
Copy
Edit
#include<stdlib.h>
Includes functions like rand(), srand(), system() and exit().

cpp
Copy
Edit
#include<string.h>
For manipulating C-style strings. Not heavily used here.

cpp
Copy
Edit
#include <windows.h>
Gives access to Windows-specific API functions like:

SetConsoleCursorPosition

GetStdHandle

CONSOLE_CURSOR_INFO

cpp
Copy
Edit
#include <time.h>
Used to generate randomness based on current time with srand(time(NULL)).

🧱 Game Constants
cpp
Copy
Edit
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
Constant	Purpose
SCREEN_WIDTH	Total width of the console screen
SCREEN_HEIGHT	Height of the console screen
WIN_WIDTH	Width of the gameplay area
MENU_WIDTH	Width of the side menu
GAP_SIZE	Vertical space between top and bottom pipes
PIPE_DIF	Distance between consecutive pipes (unused here but could be for multiple pipes)
🌐 Global Variables
cpp
Copy
Edit
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
Used to control and move the console cursor.

cpp
Copy
Edit
int pipePos[3], gapPos[3], pipeFlag[3];
pipePos[]: X-positions of the pipes

gapPos[]: Where the gap in each pipe is

pipeFlag[]: Whether that pipe is currently active

cpp
Copy
Edit
char bird[2][6] = {
    '/','-','-','o','\\',' ',
    '|','_','_','_',' ','>'
};
ASCII art for the bird, drawn as two rows.

cpp
Copy
Edit
int birdPos = 6;
int score = 0;
birdPos: Vertical position of the bird

score: How many pipes the bird has passed

🖱️ Cursor Control Functions
Move cursor to (x, y)
cpp
Copy
Edit
void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
Hide or Show the Cursor
cpp
Copy
Edit
void setcursor(bool visible, DWORD size) {
    if(size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}
📐 Drawing Functions
Draw the Game Border
cpp
Copy
Edit
void drawBorder() {
    for(int i = 0; i < SCREEN_WIDTH; i++) {
        gotoxy(i, 0); cout << "═";
        gotoxy(i, SCREEN_HEIGHT); cout << "═";
    }
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(0, i); cout << "║";
        gotoxy(SCREEN_WIDTH, i); cout << "║";
        gotoxy(WIN_WIDTH, i); cout << "║"; // Separator for menu
    }
}
Generate Pipe Gap
cpp
Copy
Edit
void genPipe(int ind) {
    gapPos[ind] = 3 + rand() % 14;  // Gap starts between row 3 and 16
}
Draw & Erase Pipes
cpp
Copy
Edit
void drawPipe(int ind) {
    if(pipeFlag[ind]) {
        for(int i = 0; i < gapPos[ind]; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "***";
        }
        for(int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "***";
        }
    }
}
cpp
Copy
Edit
void erasePipe(int ind) {
    if(pipeFlag[ind]) {
        for(int i = 0; i < gapPos[ind]; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "   ";
        }
        for(int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "   ";
        }
    }
}
Draw & Erase the Bird
cpp
Copy
Edit
void drawBird() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            gotoxy(j + 2, i + birdPos); cout << bird[i][j];
        }
    }
}
cpp
Copy
Edit
void eraseBird() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            gotoxy(j + 2, i + birdPos); cout << " ";
        }
    }
}
💥 Collision Detection
cpp
Copy
Edit
int collision() {
    if(pipePos[0] >= 61) {
        if(birdPos < gapPos[0] || birdPos > gapPos[0] + GAP_SIZE) {
            return 1; // Collision
        }
    }
    return 0;
}
Checks if the bird’s Y-position is within the pipe gap or not.

🎮 Game Over
cpp
Copy
Edit
void gameover() {
    system("cls");
    cout << "\n\t\t--------------------------\n";
    cout << "\t\t-------- Game Over -------\n";
    cout << "\t\t--------------------------\n\n";
    cout << "\t\tPress any key to go back to menu.";
    getch();
}
🧮 Score Update
cpp
Copy
Edit
void updateScore() {
    gotoxy(WIN_WIDTH + 7, 5); cout << "Score: " << score << endl;
}
📘 Instructions Screen
cpp
Copy
Edit
void instructions() {
    system("cls");
    cout << "Instructions\n";
    cout << "----------------\n";
    cout << " Press spacebar to make bird fly\n";
    cout << "\nPress any key to go back to menu";
    getch();
}
🕹️ Main Game Logic
cpp
Copy
Edit
void play() {
    birdPos = 6;
    score = 0;
    pipeFlag[0] = 1;
    pipeFlag[1] = 0;
    pipePos[0] = pipePos[1] = 4;

    system("cls");
    drawBorder();
    genPipe(0);
    updateScore();

    gotoxy(WIN_WIDTH + 5, 2); cout << "FLAPPY BIRD";
    gotoxy(WIN_WIDTH + 2, 14); cout << " Spacebar = jump";
    gotoxy(10, 5); cout << "Press any key to start";
    getch();
    gotoxy(10, 5); cout << "                      ";

    while(1) {
        if(kbhit()) {
            char ch = getch();
            if(ch == 32 && birdPos > 3) birdPos -= 3;
            if(ch == 27) break;
        }

        drawBird();
        drawPipe(0);
        drawPipe(1);

        if(collision()) {
            gameover();
            return;
        }

        Sleep(100);
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        birdPos += 1;

        if(birdPos > SCREEN_HEIGHT - 2) {
            gameover();
            return;
        }

        if(pipeFlag[0]) pipePos[0] += 2;
        if(pipeFlag[1]) pipePos[1] += 2;

        if(pipePos[0] >= 40 && pipePos[0] < 42) {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }

        if(pipePos[0] > 68) {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }
    }
}
🚪 Main Menu & Program Entry Point
cpp
Copy
Edit
int main() {
    setcursor(0, 0);  // Hide cursor
    srand((unsigned)time(NULL));  // Seed for randomness

    do {
        system("cls");
        gotoxy(10,5); cout<<" -------------------------- "; 
        gotoxy(10,6); cout<<" |      Flappy Bird       | "; 
        gotoxy(10,7); cout<<" --------------------------";
        gotoxy(10,9); cout<<"1. Start Game";
        gotoxy(10,10); cout<<"2. Instructions";     
        gotoxy(10,11); cout<<"3. Quit";
        gotoxy(10,13); cout<<"Select option: ";

        char op = getche();
        if(op == '1') play();
        else if(op == '2') instructions();
        else if(op == '3') exit(0);

    } while(1);

    return 0;
}
🖼️ Where to Keep Images
If you're documenting this project (like in a GitHub README), place screenshots or images of gameplay in a folder called images/, then embed them like this:

markdown
Copy
Edit
![Flappy Bird Screenshot](images/flappy_screenshot.png)
Make sure the image path is relative to the .md file.

🧠 Summary
This C++ game simulates Flappy Bird in the Windows console.

It uses manual drawing with gotoxy() and ASCII art.

Pipe obstacles move toward the bird, and you must press space to avoid crashing.

No external libraries required — just a basic Windows-compatible C++ setup.

