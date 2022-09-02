/*
 * @operator_overloading.cpp
 * @author lvintila (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 * operator overloading means giving a new meaning to 
 * adding parameters to
 * creating essentially
 * allowed to define or change the beheaver of an operator
 * 
 */

#include <iostream>
#include <string>

struct Vector2
{
    float   x, y;

    Vector2(float x, float y)
        : x(x), y(y)
    {
    }
    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator+(const Vector2 &other) const
    {
        return Add(other);
    }
    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2 &other) const
    {
        return Multiply(other);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

//    Vector2 result1 = position.Add(speed.Multiply(powerup));
    Vector2 result2 = position + speed * powerup;

    std::cout << result2 << std::endl;

}