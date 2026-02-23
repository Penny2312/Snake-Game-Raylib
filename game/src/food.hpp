#pragma once
#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;

class Snake;

extern int cellSize;
extern int cellCount;
extern int offset;
extern Color green;
extern Color darkGreen;

bool ElementInDeque(Vector2 element, deque<Vector2> deque);

class Food {
public:
    Vector2 position;
    Texture2D texture;

    Food(deque<Vector2> snakeBody);
    ~Food();

    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(deque<Vector2> snakeBody);
};