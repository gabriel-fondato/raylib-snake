#pragma once
#include <raylib.h>
#include "colors.h"
class Food {

    
    public:
        Vector2 pos = {5,6};
        
    Food(int cellCount) {
      setRandomPos(cellCount);
    };

    void setRandomPos(int cellCount) {
      pos = Vector2{static_cast<float>(GetRandomValue(0,cellCount-1)),static_cast<float>(GetRandomValue(0,cellCount-1))};
      std::cout << "food pos: " << pos.x << " " << pos.y << std::endl;
      
    };

    void Draw(int cellSize) {
      Rectangle foodRect = Rectangle{pos.x*cellSize,pos.y*cellSize,cellSize,cellSize};
      DrawRectangleRounded(foodRect,0.5,6,fruit_gray);
    };
};