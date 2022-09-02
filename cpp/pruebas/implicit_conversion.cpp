/*
 * @implicit_conversion.cpp
 * @author lvintila (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 * Create/Instantiate objects
 * 
 */

#include <iostream>
#include <string>


class Entity
{
    private:
        std::string m_Name;
        int m_Age;
    public:
        Entity (const std::string &name)
            : m_Name(name), m_Age(-1)
        {
        }
        Entity (int age)
            : m_Name("Unknown"), m_Age(age)
        {
        }
};

void PrintEntity(const Entity &entity)
{
    // Printing
}

int main()
{
    PrintEntity(22);
//    PrintEntity("Leo"); => no se puede escribir así porque no hay constructor disponible para transformar char array en entity
    PrintEntity(std::string("Leo")); // esta es la forma de hacer que funcione
    //or:
    PrintEntity(Entity("Cherno")); // tambien vale

    Entity a("Cherno"); // Entity e = "Cherno"; =>> implicit conversion
    Entity b(22);       // Entity b = 22; esta última es implicit conversion
    std::cin.get();
}