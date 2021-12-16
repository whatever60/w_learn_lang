#include <iostream>
#include <memory>
#include <string>
class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
    void print()
    {
        std::cout << "Entity" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Entity> entity(new Entity());
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // the preferred way. slightly safer if an exception is thrown.
    // std::unique_ptr<Entity> entity = new Entity(); // this is wrong, because the constructor is explicit.
    // std::unique_ptr<Entity> another_entity = entity; // you cannot copy an unique_ptr.
    // Copy constructor and copy assignment operator of unique pointers are deleted.
    entity->print();

}
