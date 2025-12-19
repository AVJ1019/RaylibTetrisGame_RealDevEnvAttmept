#include "mainMenu.h"

mainMenu::mainMenu(AssetMananger *am) : Scene(am)
{
    float buttonWidth = 300;
    float buttonheight = 50;

    float buttonCenter = GetScreenWidth() / 2;

    auto numButtons{3};
    float spacing = GetScreenHeight() / (numButtons + 1);
    for (auto i{0}; i <= numButtons; i++)
    {
        float posX = buttonCenter - (buttonWidth / 2);
        float posY = (spacing * i) - buttonheight;
        buttons.emplace_back(Rectangle{posX, posY, buttonWidth, buttonheight});
    }
}

void mainMenu::draw(Renderer *renderer)
{
    for (auto &b : buttons)
        renderer->drawRectangle(b, DARKGRAY);
}

void mainMenu::update(float dt)
{
}