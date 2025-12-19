#include "SceneManager.h"

bool SceneManager::togglePause()
{
    isPaused = !isPaused;
    return isPaused;
}

void SceneManager::changeScene(Scene *newScene)
{
    if (currentScene != nullptr)
    {
        delete currentScene;
    }
    currentScene = newScene;
}

void SceneManager::update(float dt)
{
    if(currentScene != nullptr && !isPaused)
    {
        currentScene->update(dt);
    }
}

void SceneManager::draw(Renderer *renderer)
{
    if(currentScene != nullptr)
    {
        currentScene->draw(renderer);
    }
}
