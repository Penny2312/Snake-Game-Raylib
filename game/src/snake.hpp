#pragma once
#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;

extern int cellSize;
extern int cellCount;
extern int offset;
extern Color darkGreen;

class Snake {
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction {1, 0};
    bool addSegment = false;

    void Draw();
    void Update();
    void Reset();
};