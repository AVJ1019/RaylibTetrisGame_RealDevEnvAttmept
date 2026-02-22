#pragma once
#include "AssetManager.h"
#include "EntityManager.h"
#include "Renderer.h"
#include "States.h"

class Scene
{
protected:
    bool sceneDone{false};
    STATES nextScene;
    AssetMananger *assets;
    EntityManager* ents = new EntityManager();

private:
public:
    Scene(AssetMananger *am) : assets(am) {}
    virtual ~Scene() {};
    virtual void update(float dt) = 0;
    virtual void draw(Renderer *renderer) = 0;
    bool isDone() { return sceneDone; }
    STATES getNextScene() { return nextScene; }
};

class SceneManager
{
private:
    Scene *currentScene = nullptr;
    bool isPaused = false;
    AssetMananger *assets = nullptr;
    
    Scene *sceneFactory(STATES toScene);
public:
    void changeScene(Scene *newScene);
    bool togglePause();
    void update(float dt);
    void draw(Renderer *renderer);

    SceneManager(AssetMananger *am) : assets(am) { currentScene = sceneFactory(STATE_MENU); }
    ~SceneManager();
};

inline SceneManager::~SceneManager() {}