#include <iostream>
#include <raylib.h>
#include "colors.h"
#include "food.h"
#include "snake.h"

using namespace std;

int cellSize = 30;
int cellCount = 25;
int points;
//const char* = "meu jogo da cobrinha. pontos:";

int delayCounter;

void delayedUpdate(Snake& snake) {
   delayCounter++;
   if(delayCounter >= 20) {
    snake.Update(cellCount, points);
    delayCounter = 0;
   };
}

void checkFood(Snake& snake, Food& food, int cellCount) {
    if(Vector2Equals(snake.body[0], food.pos)) {
        food.setRandomPos(cellCount);
        snake.increseSize();
        cout << "food eat" << endl;
        points++;
        cout << "points: " << points << endl;
        //SetWindowTitle("meu jogo da cobrinha. pontuação:" << points);
    }
}

int main () {
    cout << "starting game" << endl;
    InitWindow(cellSize * cellCount,cellSize * cellCount,"meu jogo da cobrinha");
    SetTargetFPS(60);

    Food food(cellCount);
    Snake snake;

    while(WindowShouldClose() == false) {

        

        if(IsKeyPressed(KEY_LEFT) && snake.direction.x !=1)
            snake.direction = {-1,0};
        if(IsKeyPressed(KEY_RIGHT) && snake.direction.x !=-1)
            snake.direction = {1,0};
        if(IsKeyPressed(KEY_DOWN) && snake.direction.y !=-1)
            snake.direction = {0,1};
        if(IsKeyPressed(KEY_UP) && snake.direction.y !=1)
            snake.direction = {0,-1};

        checkFood(snake,food,cellCount);
        snake.checkEdgeColision(cellCount, points);


        BeginDrawing();

        food.Draw(cellSize);
        snake.Draw(cellSize);

        ClearBackground(background_white);
        EndDrawing();
        delayedUpdate(snake);
    }

    CloseWindow();
    return 0;
}