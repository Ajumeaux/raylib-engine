/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Input
*/

#ifndef TEXTURE2D_HPP_
#define TEXTURE2D_HPP_

#pragma once

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Texture2D : public ::Texture2D {
        public:
            Texture2D(const std::string& fileName) {
                printf("Loading texture %s\n", fileName.c_str());
                ::Texture2D texture = ::LoadTexture(fileName.c_str());
                this->format = texture.format;
                this->id = texture.id;
                this->height = texture.height;
                this->width = texture.width;
                this->mipmaps = texture.mipmaps;
            }
            Texture2D(const std::string& fileName, int width, int height) {
                ::Texture2D texture = ::LoadTextureFromImage(::LoadImage(fileName.c_str()));
                this->format = texture.format;
                this->id = texture.id;
                this->height = texture.height;
                this->width = texture.width;
                this->mipmaps = texture.mipmaps;
            }
            inline int getWidth() const {
                return this->width;
            }
            inline int getHeight() const {
                return this->height;
            }
            inline void unload() {
                ::UnloadTexture(*this);
            }
            
            inline void draw(const Raylib::Vector2& position) {
				::DrawTextureEx(*this, position, 0, 1, WHITE);
            }
            inline void draw(const Raylib::Vector2& position, const Raylib::Vector2& scale) {
                ::DrawTextureEx(*this, position, 0, scale.x, WHITE);
            }
            inline void draw(const Raylib::Vector2& position, const Raylib::Vector2& scale, float rotation) {
                ::DrawTextureEx(*this, position, rotation, scale.x, WHITE);
            }
            inline void draw(const ::Rectangle& source, const ::Rectangle& dest, const Raylib::Vector2& origin, float rotation) {
                ::DrawTexturePro(*this, source, dest, origin, rotation, WHITE);
            }
        protected:
        private:

    };
}

#endif /* !TEXTURE2D_HPP_ */