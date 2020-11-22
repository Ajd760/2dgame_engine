#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include ".\Entity.h"
#include ".\Component.h"

class EntityManager {
    public:
        void Update(float deltaTime);
        void Render();
        bool IsEmpty() const;
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount() const;
        void DestroyEverything();
        void ListEntities() const;

    protected:
        std::vector<Entity*> entities;
};

#endif