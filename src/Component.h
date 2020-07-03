#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component 
{
    public:
        Entity* owner;
        Component();
        virtual ~Component();
        virtual void init();
        virtual void update(float deltaTime);
        virtual void render();

    protected:

};

#endif