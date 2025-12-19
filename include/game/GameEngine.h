#pragma once
#include "SceneManager.h"
#include "EntityManager.h"

#define GAME_WIDTH 1920
#define GAME_HEIGHT 1080

class GameEngine
{
private:
    SceneManager *sceneManager;
    AssetMananger *assetManager;
    Renderer *renderer;
    float dt;

public:
    GameEngine() = default;
    ~GameEngine();
    void run();
    void handleInput();
    void update(float dt);
    void draw();
};

inline GameEngine::~GameEngine()
{
    delete sceneManager;
    delete assetManager;
}