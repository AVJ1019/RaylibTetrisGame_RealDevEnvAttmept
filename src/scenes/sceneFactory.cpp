#include "SceneManager.h"
// Scenes
#include "mainMenu.h"
#include "Start.h"
#include "Game_over.h"
#include "config.h"

Scene *SceneManager::sceneFactory(STATES toScene, int score)
{
    switch (toScene)
    {
    case (STATE_MENU):
        return new mainMenu(assets);
        break;
    case (STATE_START):
        return new Start(assets);
        break;
    case (STATE_OPTION):
        return nullptr;
        break;
    case (STATE_EXIT):
        return nullptr;
        break;
    case (STATE_GAME_OVER):
        return new Game_over(assets, score);
        break;
    }
    return nullptr;
}
