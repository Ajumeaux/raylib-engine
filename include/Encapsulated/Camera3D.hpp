/*
** EPITECH PROJECT, 2023
** game
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Camera : public ::Camera3D {
    public:
        Camera(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection) : 
        ::Camera3D{position, target, up, fovy, projection} {}

        void beginMode3D() {
            ::BeginMode3D(*this);
        }
        void endMode3D() {
            ::EndMode3D();
        }
        inline ::Matrix getMatrix() const {
            return ::GetCameraMatrix(*this);
        }
        inline void setMode(int mode) {
            ::SetCameraMode(*this, mode);
        }
        inline void update() {
            ::UpdateCamera(this);
        }

        inline void update(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection) {
            ::UpdateCamera(this);
        }
        inline void update(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection, int mode) {
            ::UpdateCamera(this);
        }
        inline void update(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection, int mode, float speed) {
            ::UpdateCamera(this);
        }
        inline void update(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection, int mode, float speed, float sensitivity) {
            ::UpdateCamera(this);
        }
        inline void update(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection, int mode, float speed, float sensitivity, float minDistance, float maxDistance) {
            ::UpdateCamera(this);
        }
    };
}

#endif