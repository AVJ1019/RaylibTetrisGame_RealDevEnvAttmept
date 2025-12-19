#pragma once
#include "AssetManager.h"
#include "Renderer.h"

class Scene
{
private:
    AssetMananger *assets;

public:
    Scene(AssetMananger *am) : assets(am) {}
    virtual ~Scene() {};
    virtual void update(float dt) = 0;
    virtual void draw(Renderer *renderer) = 0;
};

class SceneManager
{
private:
    Scene *currentScene = nullptr;
    bool isPaused = false;

public:
    void changeScene(Scene *newScene);
    bool togglePause();
    void update(float dt);
    void draw(Renderer *renderer);

    SceneManager() = default;
    ~SceneManager();
};

inline SceneManager::~SceneManager() {}