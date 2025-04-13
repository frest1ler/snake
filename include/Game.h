#pragma once
#include <SFML/Graphics.hpp>

// Выносим константы в глобальную область видимости
constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr int GRID_SIZE = 20;
constexpr int GRID_WIDTH = WIDTH / GRID_SIZE;
constexpr int GRID_HEIGHT = HEIGHT / GRID_SIZE;

class Game {
    sf::RenderWindow window;
    
    void processInput();
    void update();
    void render();
    
public:
    Game();
    void run();
};