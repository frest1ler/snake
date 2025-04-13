#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Game {
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
    static const int GRID_SIZE = 20;
    static const int GRID_WIDTH = WIDTH / GRID_SIZE;
    static const int GRID_HEIGHT = HEIGHT / GRID_SIZE;
    
    sf::RenderWindow window;
    Snake snake;
    Food food;
    
    void processInput();
    void update();
    void render();
    
public:
    Game();
    void run();
};