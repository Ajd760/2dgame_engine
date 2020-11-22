#include ".\EntityManager.h"
#include <iostream>

void EntityManager::Update(float deltaTime) {
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Update(deltaTime);
    }
}
void EntityManager::Render() {
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Render();
    }
}

bool EntityManager::IsEmpty() const {
    return entities.empty();
}

Entity& EntityManager::AddEntity(std::string entityName) {
    Entity* entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const {
    return entities;
}

unsigned int EntityManager::GetEntityCount() const {
    return entities.size();
}

void EntityManager::DestroyEverything() {
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Destroy();
    }
}

void EntityManager::ListEntities() const {
    for(int i = 0; i < entities.size(); i++) {
        std::cout << "Entity Name: " << entities[i]->name << std::endl;
        for(int j = 0; j < entities[i]->GetNumComponents(); j++) {
            std::cout << "\tComponent<" << entities[i]->GetComponentByIndex(j)->GetType() << ">" << std::endl;
        }
    }
}