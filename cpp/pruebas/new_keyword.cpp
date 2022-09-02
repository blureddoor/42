/*
 * @new_keyword.cpp
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
    public:
        Entity() : m_Name("Unknown")
        {
        }
        Entity(const std::string &name) : m_Name(name)
        {
        }
};

int main()
{
    int a = 2;
    int *b = new int;
    int *c = new int[50];
    Entity *e = new Entity();
    // entity *e = new Entity[50]; 

    delete b;
    delete[] c; // si se declara con [] se tiene que liberar con []
    delete e;

    return (0);
}