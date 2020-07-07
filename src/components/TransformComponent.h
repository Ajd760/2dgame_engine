#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "..\Game.h"
#include "..\EntityManager.h"
#include "..\..\lib\glm\glm.hpp"
#include <SDL2\SDL.h>

class TransformComponent : public Component
{
    public:
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s);
        void init() override;
        void update(float deltaTime) override;
        void render() override;
        std::string getType() const override;

        glm::vec2 position;
        glm::vec2 velocity;
        int width;
        int height;
        int scale;

        const std::string componentType = "TransformComponent";
};


#endif