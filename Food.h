#pragma once
#include <random>

enum class FoodType {
    Normal,
    Special
};

struct Food {
    int x, y;
    FoodType type;
    
    Food();
    void respawn();
};