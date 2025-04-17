#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyX[3], enemyY[3], enemyFlag[3];
int bullets[20][4];
int bIndex = 0;
int birdPos = WIN_WIDTH / 2;
int score = 0;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder() {
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        gotoxy(i, SCREEN_HEIGHT); cout << "±";
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(0, i); cout << "±";
        gotoxy(SCREEN_WIDTH, i); cout << "±";
        gotoxy(WIN_WIDTH, i); cout << "±";
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void drawBird() {
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(birdPos, 22);     cout << "  🚀  ";
    gotoxy(birdPos, 23);     cout << "  🛸  ";
    gotoxy(birdPos, 24);     cout << " 🌀🌀🌀 ";
}

void eraseBird() {
    for (int i = 0; i < 3; i++) {
        gotoxy(birdPos, 22 + i); cout << "      ";
    }
}

void genEnemy(int ind) {
    enemyX[ind] = 3 + rand() % (WIN_WIDTH - 10);
}

void drawEnemy(int ind) {
    if (enemyFlag[ind]) {
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
        gotoxy(enemyX[ind], enemyY[ind]);     cout << " 👾 ";
        gotoxy(enemyX[ind], enemyY[ind] + 1); cout << "💥💥";
    }
}

void eraseEnemy(int ind) {
    if (enemyFlag[ind]) {
        gotoxy(enemyX[ind], enemyY[ind]);     cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 1); cout << "    ";
    }
}

void resetEnemy(int ind) {
    eraseEnemy(ind);
    enemyY[ind] = 4;
    genEnemy(ind);
}

void genBullet() {
    bullets[bIndex][0] = 22;
    bullets[bIndex][1] = birdPos + 1;
    bullets[bIndex][2] = 22;
    bullets[bIndex][3] = birdPos + 4;
    bIndex = (bIndex + 1) % 20;
}

void moveBullet() {
    for (int i = 0; i < 20; i++) {
        if (bullets[i][0] > 2) bullets[i][0]--;
        else bullets[i][0] = 0;

        if (bullets[i][2] > 2) bullets[i][2]--;
        else bullets[i][2] = 0;
    }
}

void drawBullets() {
    for (int i = 0; i < 20; i++) {
        if (bullets[i][0] > 1) {
            gotoxy(bullets[i][1], bullets[i][0]); cout << "🔹";
            gotoxy(bullets[i][3], bullets[i][2]); cout << "🔹";
        }
    }
}

void eraseBullets() {
    for (int i = 0; i < 20; i++) {
        if (bullets[i][0] >= 1) {
            gotoxy(bullets[i][1], bullets[i][0]); cout << " ";
            gotoxy(bullets[i][3], bullets[i][2]); cout << " ";
        }
    }
}

void eraseBullet(int i) {
    gotoxy(bullets[i][1], bullets[i][0]); cout << " ";
    gotoxy(bullets[i][3], bullets[i][2]); cout << " ";
}

bool checkCollisionForEnemy(int i) {
    int bx = birdPos, by = 22, bw = 5, bh = 3;
    int ex = enemyX[i], ey = enemyY[i], ew = 3, eh = 2;

    bool xOverlap = (bx + bw - 1 >= ex) && (bx <= ex + ew - 1);
    bool yOverlap = (by + bh - 1 >= ey) && (by <= ey + eh - 1);
    return (xOverlap && yOverlap);
}

bool collision() {
    for (int i = 0; i < 2; i++) {
        if (enemyFlag[i] && checkCollisionForEnemy(i))
            return true;
    }
    return false;
}

int bulletHit() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j += 2) {
            if (bullets[i][j] != 0) {
                for (int e = 0; e < 2; e++) {
                    if (bullets[i][j] >= enemyY[e] && bullets[i][j] <= enemyY[e] + 1 &&
                        bullets[i][j + 1] >= enemyX[e] && bullets[i][j + 1] <= enemyX[e] + 2) {
                        eraseBullet(i);
                        bullets[i][j] = 0;
                        resetEnemy(e);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void gameover() {
    system("cls");
    cout << "\n\t\t💀💀💀 GAME OVER 💀💀💀\n\n";
    cout << "\t\tFinal Score: " << score << "\n";
    cout << "\n\t\tPress any key to return to menu...";
    getch();
}

void updateScore() {
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(WIN_WIDTH + 7, 5); cout << "Score: " << score << "   ";
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void instructions() {
    system("cls");
    cout << "🎮 Instructions 🎮";
    cout << "\n--------------------";
    cout << "\n A - Move Left";
    cout << "\n D - Move Right";
    cout << "\n Space - Shoot 🔫";
    cout << "\n Avoid enemies (👾)!";
    cout << "\n\nPress any key to go back...";
    getch();
}

void play() {
    birdPos = WIN_WIDTH / 2 - 1;
    score = 0;
    enemyFlag[0] = enemyFlag[1] = 1;
    enemyY[0] = enemyY[1] = 4;
    for (int i = 0; i < 20; i++)
        bullets[i][0] = bullets[i][1] = bullets[i][2] = bullets[i][3] = 0;

    system("cls");
    drawBorder();
    genEnemy(0); genEnemy(1);
    updateScore();

    gotoxy(WIN_WIDTH + 5, 2); cout << "🚀 Space Shooter 🚀";
    gotoxy(WIN_WIDTH + 6, 4); cout << "----------";
    gotoxy(WIN_WIDTH + 7, 12); cout << "Controls";
    gotoxy(WIN_WIDTH + 7, 13); cout << "--------";
    gotoxy(WIN_WIDTH + 2, 14); cout << "A - Left";
    gotoxy(WIN_WIDTH + 2, 15); cout << "D - Right";
    gotoxy(WIN_WIDTH + 2, 16); cout << "Space - Shoot";
    gotoxy(10, 5); cout << "Press any key to start 🚀";
    getch();
    gotoxy(10, 5); cout << "                      ";

    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 'a' || ch == 'A') {
                if (birdPos > 2) birdPos -= 2;
            }
            if (ch == 'd' || ch == 'D') {
                if (birdPos < WIN_WIDTH - 7) birdPos += 2;
            }
            if (ch == 32) genBullet();
            if (ch == 27) break; // ESC to quit
        }

        drawBird();
        drawEnemy(0);
        drawEnemy(1);
        drawBullets();

        if (collision()) {
            gameover();
            return;
        }

        if (bulletHit()) {
            score++;
            updateScore();
        }

        Sleep(100);

        eraseBird();
        eraseEnemy(0);
        eraseEnemy(1);
        eraseBullets();
        moveBullet();

        if (enemyFlag[0]) enemyY[0]++;
        if (enemyFlag[1]) enemyY[1]++;

        if (enemyY[0] > SCREEN_HEIGHT - 4) resetEnemy(0);
        if (enemyY[1] > SCREEN_HEIGHT - 4) resetEnemy(1);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Enable emoji display
    setcursor(0, 0);
    srand((unsigned)time(0));

    while (true) {
        system("cls");
        gotoxy(10, 5); cout << " ============================ ";
        gotoxy(10, 6); cout << " |     🚀 Space Shooter     | ";
        gotoxy(10, 7); cout << " ============================ ";
        gotoxy(10, 9); cout << "1. Start Game 🎮";
        gotoxy(10, 10); cout << "2. Instructions 📜";
        gotoxy(10, 11); cout << "3. Quit ❌";
        gotoxy(10, 13); cout << "Select option: ";
        char op = getche();

        if (op == '1') play();
        else if (op == '2') instructions();
        else if (op == '3') break;
    }

    return 0;
}