#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include ".\Component.h"

class EntityManager;

class Entity {
    public:
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        void Update(float deltaTime);
        void Render();
        void Destroy();
        bool GetIsActive() const;
        int GetNumComponents() const;
        Component* GetComponentByIndex(int index) const;

        std::string name;

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... args) {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->Init();
            return *newComponent;
        }

    protected:
        EntityManager& manager;
        bool bisActive;
        std::vector<Component*> components;
};

#endif