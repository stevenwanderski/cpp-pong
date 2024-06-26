class Paddle
{
public:
    Paddle(float x, float y, float winHeight, KeyboardKey upKey, KeyboardKey downKey);
    void tick(float deltaTime);
    Rectangle getCollisionRec();
    int getScore();
    void increaseScore();

private:
    float x{};
    float y{};
    float winHeight{};
    float height = 100.f;
    float width = 10.f;
    float speed = 400.f;
    int score = 0;
    KeyboardKey upKey{};
    KeyboardKey downKey{};
};