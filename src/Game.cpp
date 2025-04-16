#include "Game.h"
#include <sstream>

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Змейка"), currentDelay(baseDelay) {
    window.setFramerateLimit(60);
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
        if (food.type == FoodType::Normal) {
            snake.grow();
            score += 10;
            // Увеличиваем скорость (уменьшаем задержку)
            currentDelay = std::max(0.05f, currentDelay * 0.95f);
        } else {
            // Специальная еда дает больше очков и увеличивает змейку на 2 сегмента
            snake.grow();
            snake.grow();
            score += 30;
            currentDelay = std::max(0.05f, currentDelay * 0.9f);
        }
        food.respawn();
        return;
    }
    
    if (snake.checkCollision()) {
        window.close();
    }
}

void Game::drawScore() {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Простой fallback, если шрифт не загрузился
        sf::Text text;
        text.setString("Score: " + std::to_string(score));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(10, 10);
        window.draw(text);
        return;
    }
    
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    window.draw(text);
}

void Game::render() {
    window.clear(sf::Color::Black);
    
    // Рисуем еду
    sf::RectangleShape foodShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    foodShape.setFillColor(food.type == FoodType::Normal ? sf::Color::Red : sf::Color::Blue);
    foodShape.setPosition(food.x * GRID_SIZE, food.y * GRID_SIZE);
    window.draw(foodShape);
    
    // Рисуем змейку
    for (const auto& segment : snake.segments) {
        sf::RectangleShape segmentShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
        segmentShape.setFillColor(sf::Color::Green);
        segmentShape.setPosition(segment.x * GRID_SIZE, segment.y * GRID_SIZE);
        window.draw(segmentShape);
    }
    
    drawScore();
    window.display();
}

void Game::run() {
    sf::Clock clock;
    float timer = 0;
    
    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;
        
        processInput();
        
        if (timer > currentDelay) {
            timer = 0;
            update();
        }
        
        render();
    }
}