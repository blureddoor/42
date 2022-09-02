/*
 * @instantiate_objects.cpp
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

//using String = std::string;

class Entity
{
    private:
        std::string m_Name;
    public:
        Entity()
            : m_Name("Unknown")
        {
        }
        Entity(const std::string &name)
            : m_Name(name)
        {
        }
        const std::string &GetName() const
        {
            return (m_Name);
        }
};

int main()
{
    /* ways to Create/Instantiate objects -> ALLOCATION IN STACK */

   /*
    Entity *e;
    {
        Entity entity("LeoV");
        e = &entity;
        std::cout << entity.GetName()<< std::endl;
    }
    */

   /* other way: ALLOCATION IN THE HEAP (when are a really big bunch of objects or the class is too too big)*/

    Entity *e;
    {
        Entity *entity = new Entity("LeoV");
        e = entity;
        std::cout << entity->GetName()<< std::endl;
    }
    delete e;
    return (0);
}