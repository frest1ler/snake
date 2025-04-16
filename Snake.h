#pragma once
#include <vector>
#include "Direction.h"

struct SnakeSegment {
    int x, y;
};

class Snake {
public:
    std::vector<SnakeSegment> segments;
    Direction direction;
    
    Snake();
    void move();
    void grow();
    bool checkCollision() const;
};