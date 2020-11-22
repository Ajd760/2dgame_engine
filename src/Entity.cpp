#include ".\Entity.h"
#include ".\EntityManager.h"
#include <iostream>

Entity::Entity(EntityManager& manager) : manager(manager) {
    bisActive = true;
}
Entity::Entity(EntityManager& manager, std::string name) : manager(manager), name(name) {
    bisActive = true;
}

void Entity::Update(float deltaTime) {
    for(int i = 0; i < components.size(); i++) {
        components[i]->Update(deltaTime);
    }
}

void Entity::Render() {
    for(int i = 0; i < components.size(); i++) {
        components[i]->Render();
    }
}

void Entity::Destroy() {
    bisActive = false;
    
    // TODO: Delete components assigned?
}

bool Entity::GetIsActive() const {
    return bisActive;
}

int Entity::GetNumComponents() const {
    return components.size();
}

Component* Entity::GetComponentByIndex(int index) const {
    if(index > components.size() || index < 0) {
        std::cerr << "Component index out of bounds" << std::endl;
        return nullptr;
    }

    return components[index];
}
