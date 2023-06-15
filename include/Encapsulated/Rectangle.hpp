/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Sound
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib
{
    class Rectangle : public ::Rectangle
    {
    public:
        Rectangle(const Raylib::Vector2 &position, const Raylib::Vector2 &size)
        {
            x = position.x;
            y = position.y;
            width = size.x;
            height = size.y;
        }
        Rectangle() = default;
        inline bool checkCollision(const Raylib::Rectangle &rectangle) const
        {
            return ::CheckCollisionRecs(*this, rectangle);
        }
        inline bool checkCollisionPoint(const Raylib::Vector2 &point) const
        {
            return ::CheckCollisionPointRec((::Vector2)point, *this);
        }

    private:
    };
}

#endif // RECTANGLE_HPP_