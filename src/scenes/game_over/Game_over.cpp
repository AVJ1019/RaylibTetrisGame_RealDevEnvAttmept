#include "Game_over.h"
#include "States.h"
Game_over::Game_over(AssetMananger *am, int score) : Scene(am), m_score(score)
{
    float xPos = GetScreenWidth() / 2;
    float yPos = GetScreenHeight() / 2;
    float btnWidth = GetScreenWidth() / 5;
    float btnHeight = GetScreenHeight() / 10;
    m_btn_exit = {xPos - (btnWidth / 2), yPos - (btnHeight / 2), btnWidth, btnHeight};
}
Game_over::~Game_over()
{
}
void Game_over::update(float dt)
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(GetMousePosition(), m_btn_exit))
        {
            sceneDone = true;
            nextScene = STATE_MENU;
        }
    }
}

void Game_over::draw(Renderer *renderer)
{
    renderer->drawButton(m_btn_exit, GRAY, "Return to main menu");
    renderer->drawText("Your score was: " + std::to_string(m_score), GetScreenWidth() / 2, m_btn_exit.y - (m_btn_exit.height * 2), 0.6, RED);
}
