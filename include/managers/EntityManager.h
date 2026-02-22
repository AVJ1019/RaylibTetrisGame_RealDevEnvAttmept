#pragma once
#include "raylib.h"
#include <vector>
#include "Renderer.h"

class entity
{
protected:
    bool alive{true};

private:
public:
    virtual ~entity() {};
    virtual void update(float dt) = 0;
    virtual void draw(Renderer *renderer) = 0;
    bool isAlive() { return alive; }
};

class EntityManager
{
private:
    std::vector<entity *> entities;

public:
    EntityManager() = default;
    ~EntityManager();

    void addEntity(entity* toAdd);
    void removeEntity(entity* toRemove);

    void update(float dt);
    void draw(Renderer *renderer);
    void unloadEntities();
};

inline EntityManager::~EntityManager()
{
    unloadEntities();
}