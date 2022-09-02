/**
 * @file member_initilizer_lists.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 * Member initializer lists - Constructer initializer list
 * 
 */

#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;   
        int m_Score;
    public:
        Entity()
            : m_Name("Desconocido"), m_Score(0)
        {
        }

        Entity(const std::string &name)
            :     m_Name(name)
        {
        }
        const std::string &GetName() const
        {
            return (m_Name);
        }
};

int main()
{
    Entity e0;
    Entity e1("lvintila");
    std::cout<< e0.GetName() << std::endl;
    std::cout<< e1.GetName() << std::endl;
    return (0);
}