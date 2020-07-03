#include ".\EntityManager.h"

void EntityManager::update(float deltaTime)
{
    for(int i = 0; i < entities.size(); i++)
    {
        entities[i]->update(deltaTime);
    }
}
void EntityManager::render()
{
    for(int i = 0; i < entities.size(); i++)
    {
        entities[i]->render();
    }
}

bool EntityManager::isEmpty() const
{
    return entities.empty();
}

Entity& EntityManager::addEntity(std::string entityName)
{
    Entity* entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::getEntities() const
{
    return entities;
}

unsigned int EntityManager::getEntityCount() const
{
    return entities.size();
}

void EntityManager::destroyEverything()
{
    for(int i = 0; i < entities.size(); i++)
    {
        entities[i]->destroy();
    }
}