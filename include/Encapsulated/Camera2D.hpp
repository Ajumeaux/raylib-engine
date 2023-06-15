/*
** EPITECH PROJECT, 2023
** game
** File description:
** Camera2D
*/

#ifndef CAMERA2D_HPP_
#define CAMERA2D_HPP_

#include "BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Camera2D : public ::Camera2D {
    public:
        Camera2D(::Vector2 offset, ::Vector2 target, float rotation, float zoom) {
            this->offset = offset;
            this->target = target;
            this->rotation = rotation;
            this->zoom = zoom;
        }
        inline void beginMode2D() {
            ::BeginMode2D(*this);
        }
        inline void endMode2D() {
            ::EndMode2D();
        }
        inline ::Matrix getMatrix() const {
            return ::GetCameraMatrix2D(*this);
        }
        inline ::Vector2 GetScreenToWorld(::Vector2 position) {
            return ::GetScreenToWorld2D(position, *this);
        }
        inline ::Vector2 GetWorldToScreen(::Vector2 position) {
            return ::GetWorldToScreen2D(position, *this);
        }
    };
}

#endif /* !CAMERA2D_HPP_ */