#pragma once
#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "snake.hpp"
#include "food.hpp"
using namespace std;

extern int cellSize;
extern int cellCount;
extern int offset;
extern Color green;
extern Color darkGreen;
extern double lastUpdateTime;

enum class ButtonPressed {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game {
public:
    Snake snake;
    Food food;
    bool running = true;
    int score = 0;
    
    Game();
    ~Game();
    void Draw();
    void Update();
    void CheckCollisionFood();
    void CheckCollisionEdge();
    void CheckCollisionTail();
    void GameOver();
    bool eventTriggered(double interval);
    void Loop();

private:
    Sound eatSound;
    Sound wallSound;
};