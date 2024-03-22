#include "raylib.h"
#include "ball.h"
#include "paddle.h"

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

    if (isRunning)
    {
      ball.tick(dT);
      paddle1.tick(dT);
      paddle2.tick(dT);
    }

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle2.getCollisionRec()))
    {
      ball.reverseX();
    }

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle1.getCollisionRec()))
    {
      ball.reverseX();
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
