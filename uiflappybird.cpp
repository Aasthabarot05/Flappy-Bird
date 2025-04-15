#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define GAP_SIZE 7
#define PIPE_DIF 45

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int pipePos[3];
int gapPos[3];
int pipeFlag[3];
string bird[2][6] = {
    {" ", " ", "🐤", " ", " ", " "},
    {" ", " ", " ", " ", " ", " "}
};
int birdPos = 6;
int score = 0;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}


void drawBorder() {
    // Top and bottom borders
    for (int i = 0; i <= WIN_WIDTH; i += 2) {
        gotoxy(i, 0); cout << "🧱";
        gotoxy(i, SCREEN_HEIGHT); cout << "🧱";
    }

    // Left and right borders
    for (int i = 1; i < SCREEN_HEIGHT; i++) {
        gotoxy(0, i); cout << "🧱";                  // Left wall
        gotoxy(WIN_WIDTH, i); cout << "🧱";          // Right wall
    }

   
}


void genPipe(int ind) {
    gapPos[ind] = 3 + rand() % 14;
}

void drawPipe(int ind) {
    if (pipeFlag[ind]) {
        for (int i = 0; i < gapPos[ind]; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "🌵";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << "🌵";
        }
    }
}

void erasePipe(int ind) {
    if (pipeFlag[ind]) {
        for (int i = 0; i < gapPos[ind]; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << " ";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++) {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1); cout << " ";
        }
    }
}

void drawBird() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            gotoxy(j + 2, i + birdPos), cout << bird[i][j];
}

void eraseBird() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            gotoxy(j + 2, i + birdPos), cout << " ";
}

int collision() {
    if (pipePos[0] >= 61) {
        if (birdPos < gapPos[0] || birdPos > gapPos[0] + GAP_SIZE)
            return 1;
    }
    return 0;
}

void gameover() {
    system("cls");
    cout << "\n\t🔥🔥🔥 GAME OVER 🔥🔥🔥\n\n";
    cout << "\tFinal Score: " << score << "\n";
    cout << "\tPress any key to return to menu...";
    getch();
}

void updateScore() {
    gotoxy(WIN_WIDTH + 6, 5);
    cout << "📈 Score: " << score << " ";
}

void instructions() {
    system("cls");
    cout << "🎮 How to Play\n";
    cout << "----------------------\n";
    cout << "Press SPACE to jump 🆙\n";
    cout << "Avoid the pipes 🌵🌵🌵\n";
    cout << "Don't hit the ceiling or floor ⛔\n";
    cout << "\nPress any key to return to menu.";
    getch();
}

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

    gotoxy(WIN_WIDTH + 3, 2); cout << "🎮 FLAPPY BIRD 🎮";
    gotoxy(WIN_WIDTH + 6, 4); cout << "-------------";
    gotoxy(WIN_WIDTH + 6, 6); cout << "🕹️ Controls:";
    gotoxy(WIN_WIDTH + 6, 7); cout << "⬆️  Space = Jump";
    gotoxy(WIN_WIDTH + 6, 8); cout << "⎋  Esc = Quit";

    gotoxy(10, 5); cout << "Press any key to start...";
    getch();
    gotoxy(10, 5); cout << "                         ";

    while (true) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 32 && birdPos > 3) birdPos -= 3;
            if (ch == 27) break;
        }

        drawBird();
        drawPipe(0);
        drawPipe(1);

        if (collision()) {
            gameover();
            return;
        }

        Sleep(100);
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        birdPos += 1;

        if (birdPos > SCREEN_HEIGHT - 2) {
            gameover();
            return;
        }

        if (pipeFlag[0]) pipePos[0] += 2;
        if (pipeFlag[1]) pipePos[1] += 2;

        if (pipePos[0] >= 40 && pipePos[0] < 42) {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }

        if (pipePos[0] > 68) {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Enable emoji support
    setcursor(0, 0);
    srand((unsigned)time(NULL));

    while (1) {
        system("cls");
        gotoxy(10, 5); cout << "🕹️ ----------------------------- 🕹️";
        gotoxy(10, 6); cout << "     🎮  WELCOME TO FLAPPY BIRD 🎮 ";
        gotoxy(10, 7); cout << "🕹️ ----------------------------- 🕹️";
        gotoxy(10, 9); cout << "1. ▶️ Start Game";
        gotoxy(10,10); cout << "2. 📜 Instructions";
        gotoxy(10,11); cout << "3. ❌ Quit";
        gotoxy(10,13); cout << "Select option: ";

        char op = getche();
        if (op == '1') play();
        else if (op == '2') instructions();
        else if (op == '3') break;
    }

    return 0;
}

