#pragma once

#include <raylib.h>
#include <utils.h>
#include <deque>
#include <raymath.h>

class Snake
{
public:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1,0};
    void Draw(int cellSize){
        for(int i = 0; i < body.size(); i++) {
            int x = body[i].x;
            int y = body[i].y;

            Rectangle snakeSegment = Rectangle{x*cellSize,y*cellSize, cellSize, cellSize};

            //DrawRectangle(x*cellSize, y*cellSize, cellSize, cellSize,snake_gray);
            DrawRectangleRounded(snakeSegment,0.5,6,snake_gray);
        };
    }

    void Update(){
        body.pop_back();
        body.push_front(Vector2Add(body[0],direction));
    }
};