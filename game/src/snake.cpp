#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "snake.hpp"
using namespace std;

void Snake::Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{offset + (float)x*cellSize, offset + (float)y*cellSize, cellSize, cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

void Snake::Update() {
    body.push_front(Vector2Add(body[0], direction));
    if (addSegment) {
        addSegment = false;
    } else {
        body.pop_back();
    }
}

void Snake::Reset() {
    body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    direction = {1, 0};
}