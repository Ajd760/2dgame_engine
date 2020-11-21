#include ".\TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s) {
    position = glm::vec2(posX, posY);
    velocity = glm::vec2(velX, velY);
    width = w;
    height = h;
    scale = s;
}

void TransformComponent::init() { }

void TransformComponent::update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void TransformComponent::render() {
    
    SDL_Rect transformRect = {
        (int) position.x,
        (int) position.y,
        width,
        height
    };
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::renderer, &transformRect);
}

std::string TransformComponent::getType() const {
    return componentType;
}