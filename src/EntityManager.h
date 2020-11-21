#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include ".\Entity.h"
#include ".\Component.h"

class EntityManager {
    public:
        void update(float deltaTime);
        void render();
        bool isEmpty() const;
        Entity& addEntity(std::string entityName);
        std::vector<Entity*> getEntities() const;
        unsigned int getEntityCount() const;
        void destroyEverything();
        void listEntities() const;

    protected:
        std::vector<Entity*> entities;
};

#endif