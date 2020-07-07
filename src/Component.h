#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

// This is fully an interface class - all functions implemented by children
class Component 
{
    public:
        Entity* owner;
        virtual ~Component() {}
        virtual void init() {}
        virtual void update(float deltaTime) {}
        virtual void render() {}
        virtual std::string getType() const {}
};

#endif