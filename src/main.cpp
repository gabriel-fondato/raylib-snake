#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "food.h"
#include "snake.h"

using namespace std;

int cellSize = 30;
int cellCount = 25;

int main () {
    cout << "starting game" << endl;
    InitWindow(cellSize * cellCount,cellSize * cellCount,"mygame");
    SetTargetFPS(60);

    Food food(cellCount);
    Snake snake;
    while(WindowShouldClose() == false) {
        snake.Update();

        BeginDrawing();

        food.Draw(cellSize);
        snake.Draw(cellSize);

        ClearBackground(background_white);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}