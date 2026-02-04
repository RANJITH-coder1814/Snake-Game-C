#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

int height = 20, width = 40;
int x, y, foodX, foodY, score;
int gameOver, flag;

void setup() {
    gameOver = 0;
    x = height / 2;
    y = width / 2;

    label1:
    foodX = rand() % (height - 2);
    if (foodX == 0)
        goto label1;

    label2:
    foodY = rand() % (width - 2);
    if (foodY == 0)
        goto label2;

    score = 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("|");

            if (i == x && j == y)
                printf("O");
            else if (i == foodX && j == foodY)
                printf("F");
            else
                printf(" ");

            if (j == width - 1)
                printf("|");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printf("-");

    printf("\nScore: %d", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': flag = 1; break;
        case 'd': flag = 2; break;
        case 'w': flag = 3; break;
        case 's': flag = 4; break;
        case 'x': gameOver = 1; break;
        default: break;
        }
    }
}

void logic() {
    Sleep(100);

    switch (flag) {
    case 1: y--; break;
    case 2: y++; break;
    case 3: x--; break;
    case 4: x++; break;
    default: break;
    }

    if (x < 0 || x > height || y < 0 || y > width)
        gameOver = 1;

    if (x == foodX && y == foodY) {
        label3:
        foodX = rand() % (height - 2);
        if (foodX == 0)
            goto label3;

        label4:
        foodY = rand() % (width - 2);
        if (foodY == 0)
            goto label4;

        score += 10;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
    }

    printf("\n\nGame Over!\nFinal Score = %d\n", score);
    return 0;
}
