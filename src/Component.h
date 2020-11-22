#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

// This is fully an interface class - all functions implemented by children
class Component {
    public:
        Entity* owner;
        virtual ~Component() {}
        virtual void Init() {}
        virtual void Update(float deltaTime) {}
        virtual void Render() {}
        virtual std::string GetType() const {}
};

#endif