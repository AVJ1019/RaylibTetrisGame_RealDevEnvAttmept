#include "EntityManager.h"
#include <iostream>

void EntityManager::addEntity(entity *toAdd)
{
    entities.emplace_back(toAdd);
}

void EntityManager::removeEntity(entity *toRemove)
{
    for(auto ite{entities.begin()}; ite < entities.end(); ite++)
    {
        if(*ite == toRemove)
        {
            delete *ite;
            entities.erase(ite);
            // std::cout << "[ENTITY MANAGER] Erased entity...\n";
            return;
        }
    }
}

void EntityManager::update(float dt)
{
    for(auto ent : entities)
        ent->update(dt);
}

void EntityManager::draw(Renderer *renderer)
{
    for(auto ent : entities)
        ent->draw(renderer);
}

void EntityManager::unloadEntities()
{
}