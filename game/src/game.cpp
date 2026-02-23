#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "game.hpp"
using namespace std;

bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

Game::Game() 
    : snake(Snake()), food(Food(snake.body)) {
    InitAudioDevice();
    eatSound = LoadSound("sounds/eat.mp3");
    wallSound = LoadSound("sounds/wall.mp3");
}

Game::~Game() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
}

void Game::Draw() {
    snake.Draw();
    food.Draw();
}

void Game::Update() {
    if (running){
        snake.Update();
        CheckCollisionFood();
        CheckCollisionEdge();
        CheckCollisionTail();
    }
}

void Game::CheckCollisionFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        PlaySound(eatSound);
        score++;
    }
}

void Game::CheckCollisionEdge() {
    if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
        GameOver();
    }
}

void Game::CheckCollisionTail() {
    deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody)) {
        GameOver();
    }
}

void Game::GameOver() {
    ClearBackground(green);
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
    PlaySound(wallSound);
}

bool Game::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void Game::Loop() {
    if (eventTriggered(0.2)) {
        Update();
    }

    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
            snake.direction = {0, -1};
            running = true;
        }
    if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
        snake.direction = {0, 1};
        running = true;
    }
    if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
        snake.direction = {1, 0};
        running = true;
    }
    if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
        snake.direction = {-1, 0};
        running = true;
    }

}