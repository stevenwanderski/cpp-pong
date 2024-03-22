#include <raylib.h>

class Ball
{
public:
    Ball(float winWidth, float winHeight);
    void tick(float deltaTime);
    Rectangle getCollisionRec();
    float xSpeed = 200.f;
    float ySpeed = 200.f;

private:
    float winWidth = 0;
    float winHeight = 0;
    float radius = 5.f;
    float x = winWidth / 2.f;
    float y = winHeight / 2.f;
};