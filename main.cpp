#include "raylib.h"
#include "ball.h"
#include "paddle.h"

int main(void)
{
  float width = 800.f;
  float height = 450.f;
  InitWindow(width, height, "Pong!");
  SetTargetFPS(60);

  Ball ball{
    width,
    height
  };

  Paddle paddle1{
    30.f,
    height / 2.f - 50.f,
    width,
    height,
    KEY_Q,
    KEY_A
  };

  Paddle paddle2{
    width - 30.f,
    height / 2.f - 50.f,
    width,
    height,
    KEY_P,
    KEY_L
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    float dT = GetFrameTime();

    ball.tick(dT);
    paddle1.tick(dT);
    paddle2.tick(dT);

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle2.getCollisionRec()))
    {
      ball.xSpeed = -ball.xSpeed;
    }

    if (CheckCollisionRecs(ball.getCollisionRec(), paddle1.getCollisionRec()))
    {
      ball.xSpeed = -ball.xSpeed;
    }

    EndDrawing();
  }
}
