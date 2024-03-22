#include <raylib.h>

class Ball
{
public:
    Ball(float winWidth, float winHeight);
    void tick(float deltaTime);
    Rectangle getCollisionRec();
    void reverseX();
    float x = 0;
    float y = 0;

private:
    float winHeight = 0;
    float radius = 5.f;
    float xSpeed = 200.f;
    float ySpeed = 200.f;
};