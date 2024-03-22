#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include <string>

int main(void)
{
  float width = 800.f;
  float height = 450.f;
  InitWindow(width, height, "Pong!");
  SetTargetFPS(60);

  bool isRunning = true;

  Ball ball{
    width,
    height
  };

  Paddle paddle1{
    30.f,
    height / 2.f - 50.f,
    height,
    KEY_Q,
    KEY_A
  };

  Paddle paddle2{
    width - 30.f,
    height / 2.f - 50.f,
    height,
    KEY_P,
    KEY_L
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    float dT = GetFrameTime();

    DrawText(std::to_string(paddle1.getScore()).c_str(), 100, 50, 20, WHITE);
    DrawText(std::to_string(paddle2.getScore()).c_str(), width - 70, 50, 20, WHITE);

    if (isRunning)
    {
      ball.tick(dT);
      paddle1.tick(dT);
      paddle2.tick(dT);
    }

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle2.getCollisionRec()))
    {
      ball.reverseX();
      paddle2.increaseScore();
    }

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle1.getCollisionRec()))
    {
      ball.reverseX();
      paddle1.increaseScore();
    }

    if (ball.x < 0.f)
    {
      isRunning = false;
      DrawText("Player 2 Wins!", 250, 50, 40, WHITE);
    }

    if (ball.x > width)
    {
      isRunning = false;
      DrawText("Player 1 Wins!", 250, 50, 40, WHITE);
    }

    EndDrawing();
  }
}
