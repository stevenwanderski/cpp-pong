#include <raylib.h>
#include "ball.h"

Ball::Ball(float winWidth, float winHeight) : winHeight(winHeight)
{
    x = winWidth / 2.f;
    y = winHeight / 2.f;
}

void Ball::tick(float deltaTime)
{
    x += xSpeed * deltaTime;
    y += ySpeed * deltaTime;

    if (y > winHeight) { ySpeed = -ySpeed; };
    if (y < 0) { ySpeed = -ySpeed; };

    DrawCircle(x, y, radius, WHITE);
}

Rectangle Ball::getCollisionRec()
{
    return Rectangle {
      x - radius,
      y - radius,
      radius * 2,
      radius * 2
    };
}

void Ball::reverseX()
{
    xSpeed = -xSpeed;
}