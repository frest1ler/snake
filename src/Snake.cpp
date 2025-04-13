#include "Snake.h"
#include "Game.h"

Snake::Snake() {
    segments.push_back({Game::GRID_WIDTH / 2, Game::GRID_HEIGHT / 2});
    direction = Direction::Right;
}

void Snake::move() {
    SnakeSegment newHead = segments[0];
    
    switch(direction) {
        case Direction::Up:    newHead.y--; break;
        case Direction::Down:  newHead.y++; break;
        case Direction::Left:  newHead.x--; break;
        case Direction::Right: newHead.x++; break;
    }
    
    segments.insert(segments.begin(), newHead);
    segments.pop_back();
}

void Snake::grow() {
    SnakeSegment tail = segments.back();
    segments.push_back(tail);
}

bool Snake::checkCollision() const {
    if (segments[0].x < 0 || segments[0].x >= Game::GRID_WIDTH ||
        segments[0].y < 0 || segments[0].y >= Game::GRID_HEIGHT) {
        return true;
    }
    
    for (size_t i = 1; i < segments.size(); ++i) {
        if (segments[0].x == segments[i].x && segments[0].y == segments[i].y) {
            return true;
        }
    }
    
    return false;
}
