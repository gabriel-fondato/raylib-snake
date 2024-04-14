#pragma once

#include <raylib.h>
#include "colors.h"
#include <deque>
#include <raymath.h>

class Snake
{
public:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}};
    void spawn() {
        body = {Vector2{6, 9}, Vector2{5, 9}};
    }
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

    void Update(int cellCount, int &points){
        body.pop_back();
        body.push_front(Vector2Add(body[0],direction));
        checkSelfColision(points);
        //checkEdgeColision(cellCount);
    }

    void increseSize() {
        body.push_back(body.back());
        //std::cout << "snake size increased " << body.back() << std::endl;
    }



    void checkEdgeColision(int cellCount, int &points) {
        if(body[1].x == cellCount ) {
            reset(points);
        } else if(body[1].x == 0) {
            reset(points);
        } else if(body[1].y == cellCount) {
            reset(points);
        } else if(body[1].y == 0) {
            reset(points);
        }

    }

    void checkSelfColision(int &points) {
        std::deque<Vector2> headlessBody = body;
        headlessBody.pop_front();
        if (ElementInDeque(body[0], headlessBody)) {
            reset(points);
        }
    }
    

    void reset(int &points){
        while(body.size() > 3){
            body.pop_back();
        }
        direction = {1,0};
        spawn();
        points = 0;
        std::cout << "game reset\n";
    }

private:
    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}
};