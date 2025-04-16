#include "Food.h"
#include "Game.h"
#include <random>

Food::Food() : type(FoodType::Normal) {
    respawn();
}

void Food::respawn() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, GRID_WIDTH - 1);
    std::uniform_int_distribution<> disY(0, GRID_HEIGHT - 1);
    std::uniform_int_distribution<> disType(0, 4); // 20% chance for special food
    
    x = disX(gen);
    y = disY(gen);
    type = (disType(gen) == 0) ? FoodType::Special : FoodType::Normal;
}