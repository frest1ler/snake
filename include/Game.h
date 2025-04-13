#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Direction.h"

// Глобальные константы
constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr int GRID_SIZE = 20;
constexpr int GRID_WIDTH = WIDTH / GRID_SIZE;
constexpr int GRID_HEIGHT = HEIGHT / GRID_SIZE;

class Game {
    sf::RenderWindow window;
    Snake snake;    // Добавляем змейку как член класса
    Food food;      // Добавляем еду как член класса
    
    void processInput();
    void update();
    void render();
    
public:
    Game();
    void run();
};