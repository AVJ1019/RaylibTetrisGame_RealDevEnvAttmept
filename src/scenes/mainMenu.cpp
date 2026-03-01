#include "mainMenu.h"
#include <iostream>

mainMenu::mainMenu(AssetMananger *am) : Scene(am)
{
    float buttonWidth = 500;
    float buttonheight = 150;

    float buttonCenter = GetScreenWidth() / 2;

    auto numButtons{3};
    float spacing = GetScreenHeight() / (numButtons + 1);
    for (auto i{1}; i <= numButtons; i++)
    {
        float posX = buttonCenter - (buttonWidth / 2);
        float posY = (spacing * i) - buttonheight;
        buttons.emplace_back(Rectangle{posX, posY, buttonWidth, buttonheight});
    }
}

void mainMenu::draw(Renderer *renderer)
{
    std::string btnNames[] = {"Start", "Options", "Exit"};
    for (auto i{0}; i < buttons.size(); i++)
    {
        renderer->drawButton(buttons[i], DARKGRAY, btnNames[i]);
    }
}

void mainMenu::update(float dt)
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        for (auto btn{0}; btn < buttons.size(); btn++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), buttons[btn]))
            {
                sceneDone = true;
                nextScene = static_cast<STATES>(btn+1);
                std::cout << "[MAINMENU] Next scene = " << btn+1 << std::endl;
            }
        }
    }
}