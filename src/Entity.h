#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include ".\Component.h"

class EntityManager;

class Entity
{
    public:
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        void update(float deltaTime);
        void render();
        void destroy();
        bool getIsActive() const;
        int getNumComponents() const;
        Component* getComponentByIndex(int index) const;

        std::string name;

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->init();
            return *newComponent;
        }

    protected:
        EntityManager& manager;
        bool bisActive;
        std::vector<Component*> components;
};

#endif