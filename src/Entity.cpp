#include ".\Entity.h"
#include ".\EntityManager.h"

Entity::Entity(EntityManager& manager) : manager(manager)
{
    bisActive = true;
}
Entity::Entity(EntityManager& manager, std::string name) : manager(manager), name(name)
{
    bisActive = true;
}

void Entity::update(float deltaTime)
{
    for(int i = 0; i < components.size(); i++)
    {
        components[i]->update(deltaTime);
    }
}

void Entity::render()
{
    for(int i = 0; i < components.size(); i++)
    {
        components[i]->render();
    }
}

void Entity::destroy()
{
    bisActive = false;
    
    // Delete components assigned?
}

bool Entity::getIsActive() const
{
    return bisActive;
}