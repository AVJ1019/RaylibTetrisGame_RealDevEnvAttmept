#pragma once
#include "raylib.h"
#include <vector>
#include "Renderer.h"

class entity
{
private:
    Vector2 position;
    bool isAlive{true};

public:
    virtual ~entity();
    virtual void updateInput() = 0;
    virtual void draw() = 0;
};

class EntityManager
{
private:
    std::vector<entity*> entities;

public:
    EntityManager() = default;
    ~EntityManager();

    void update();
    void draw(Renderer& renderer);
    void unloadEntities();
};

inline EntityManager::~EntityManager()
{
    unloadEntities();
}