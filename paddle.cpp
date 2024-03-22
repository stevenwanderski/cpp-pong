#include <raylib.h>
#include "paddle.h"

Paddle::Paddle(float x, float y, float winHeight, KeyboardKey upKey, KeyboardKey downKey):
    x(x),
    y(y),
    winHeight(winHeight),
    upKey(upKey),
    downKey(downKey)
{
}

void Paddle::tick(float deltaTime)
{
    if (IsKeyDown(downKey) && y < winHeight - height)
    {
        y += speed * deltaTime;
    };

    if (IsKeyDown(upKey) && y > 0)
    {
        y -= speed * deltaTime;
    };

    DrawRectangle(x, y, width, height, WHITE);
}

Rectangle Paddle::getCollisionRec()
{
    return Rectangle{
      x,
      y,
      width,
      height
    };
}