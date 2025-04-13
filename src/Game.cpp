#include "Game.h"

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Змейка") {
    window.setFramerateLimit(10);
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        if (event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                case sf::Keyboard::Up:
                    if (snake.direction != Direction::Down)
                        snake.direction = Direction::Up;
                    break;
                case sf::Keyboard::Down:
                    if (snake.direction != Direction::Up)
                        snake.direction = Direction::Down;
                    break;
                case sf::Keyboard::Left:
                    if (snake.direction != Direction::Right)
                        snake.direction = Direction::Left;
                    break;
                case sf::Keyboard::Right:
                    if (snake.direction != Direction::Left)
                        snake.direction = Direction::Right;
                    break;
            }
        }
    }
}

void Game::update() {
    snake.move();
    
    // Проверяем съедание еды
    if (snake.segments[0].x == food.x && snake.segments[0].y == food.y) {
        snake.grow();       // Сначала увеличиваем змейку
        food.respawn();     // Затем перемещаем еду
        
        // Пропускаем проверку столкновений в этом кадре
        return;
    }
    
    // Проверяем столкновения только если не было поедания еды
    if (snake.checkCollision()) {
        window.close();
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    
    // Рисуем еду
    sf::RectangleShape foodShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition(food.x * GRID_SIZE, food.y * GRID_SIZE);
    window.draw(foodShape);
    
    // Рисуем змейку
    for (const auto& segment : snake.segments) {
        sf::RectangleShape segmentShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
        segmentShape.setFillColor(sf::Color::Green);
        segmentShape.setPosition(segment.x * GRID_SIZE, segment.y * GRID_SIZE);
        window.draw(segmentShape);
    }
    
    window.display();
}

void Game::run() {
    sf::Clock clock;
    float timer = 0;
    float delay = 0.1f;
    
    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;
        
        processInput();
        
        if (timer > delay) {
            timer = 0;
            update();
        }
        
        render();
    }
}