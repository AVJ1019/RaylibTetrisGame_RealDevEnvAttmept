#include "SceneManager.h"
// Scenes
#include "mainMenu.h"
#include "Start.h"
#include "config.h"

Scene *SceneManager::sceneFactory(STATES toScene)
{
    switch (toScene)
    {
    case (STATE_MENU):
        return new mainMenu(assets);
        break;
    case (STATE_START):
        return new Start(assets, ROWS, COLS);
        break;
    case (STATE_OPTION):
        return nullptr;
        break;
    case (STATE_EXIT):
        return nullptr;
        break;
    }
    return nullptr;
}
