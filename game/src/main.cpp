#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "game.hpp"
#include "snake.hpp"
#include "food.hpp"
using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int frame = cellSize * cellCount;
int offset = 75;
int HS = 0;

double lastUpdateTime = 0;

int main() {
    cout << "STARTING SNAKE..." << endl;
    InitWindow(2*offset + frame, 2*offset + frame, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();
        game.Loop();
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset -5, (float)offset - 5, (float)frame + 10, (float)frame + 10}, 5, darkGreen);
        DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + frame + 10, 40, darkGreen);
        game.Draw();
        EndDrawing();

        if (game.score > HS) {
            HS = game.score;
        }
        DrawText(TextFormat("Highscore: %i", HS), offset + frame - 243, offset + frame + 10, 40, darkGreen);
    }
    CloseWindow();
    return 0;
}