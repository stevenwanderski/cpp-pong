class Paddle
{
public:
    Paddle(float x, float y, float winWidth, float winHeight, KeyboardKey upKey, KeyboardKey downKey);
    void tick(float deltaTime);
    Rectangle getCollisionRec();

private:
    float x{};
    float y{};
    float winWidth{};
    float winHeight{};
    float height = 100.f;
    float width = 10.f;
    float speed = 400.f;
    KeyboardKey upKey{};
    KeyboardKey downKey{};
};