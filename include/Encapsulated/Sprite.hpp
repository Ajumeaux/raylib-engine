/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix->guitton
** File description:
** Input
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#pragma once

#include "./BaseRaylib.hpp"
#include "./Texture2D.hpp"
#include "./Rectangle.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Sprite {
        public:
			Sprite(const std::string& fileName, const Raylib::Vector2& position, const Raylib::Vector2& origin, const Raylib::Vector2& parentPos) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName);
				_origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(Raylib::Vector2(0, 0), Raylib::Vector2(_texture->getWidth(), _texture->getHeight()));
				_parentPos = std::make_shared<Raylib::Vector2>(parentPos);
				_position = std::make_shared<Raylib::Vector2>(position);
                _active = true;
                _isAnimated = false;
            }
            Sprite(const std::string& fileName, int width, int height) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _rect = std::make_shared<Raylib::Rectangle>(Raylib::Vector2(0, 0), Raylib::Vector2(_texture->getWidth(), _texture->getHeight()));
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
                _isAnimated = false;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(Raylib::Vector2(0, 0), Raylib::Vector2(_texture->getWidth(), _texture->getHeight()));
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
                _isAnimated = false;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
                _isAnimated = false;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect, float hitbox) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
                _isAnimated = false;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect, float hitbox, bool isAnimated) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _isAnimated = isAnimated;
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect, float hitbox, bool isAnimated, int frameCount) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _isAnimated = isAnimated;
                _frameCount = frameCount;
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
            }
            Sprite(const std::string& fileName, const Raylib::Vector2& position, bool isAnimated, int frameCount, float frameSpeed, bool isLooped) {
                // actual Sprite for animation
                _texture = std::make_shared<Raylib::Texture2D>(fileName);
                _position = std::make_shared<Raylib::Vector2>(position);
                _origin = std::make_shared<Raylib::Vector2>((float)_texture->getHeight() / 2, (float)_texture->getHeight() / 2);
                _rect = std::make_shared<Raylib::Rectangle>(Raylib::Rectangle({0, 0}, {_texture->getWidth() / frameCount, _texture->getHeight()}));
                _parentPos = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _isAnimated = isAnimated;
                _isLooped = isLooped;
                _frameCount = frameCount;
                _frameCounter = 0;
                _currentFrame = 0;
                _frameSpeed = frameSpeed;
                _active = true;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect, bool isAnimated, int frameCount, float frameSpeed, bool isLooped) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _isAnimated = isAnimated;
                _frameCount = frameCount;
                _frameSpeed = frameSpeed;
                _isLooped = isLooped;
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
            }
            Sprite(const std::string& fileName, int width, int height, const Raylib::Vector2& origin, const Raylib::Rectangle& rect, bool isAnimated, int frameCount, float frameSpeed, bool isLooped, float clock) {
                _texture = std::make_shared<Raylib::Texture2D>(fileName, width, height);
                _origin = std::make_shared<Raylib::Vector2>(origin);
                _rect = std::make_shared<Raylib::Rectangle>(rect);
                _isAnimated = isAnimated;
                _frameCount = frameCount;
                _frameSpeed = frameSpeed;
                _isLooped = isLooped;
                _position = std::make_shared<Raylib::Vector2>(Raylib::Vector2(0, 0));
                _active = true;
            }
			inline void setParentPos(Raylib::Vector2 newparentPos) {
				*_parentPos = newparentPos;
			}
            inline Raylib::Vector2 getOrigin() const {
                return *_origin;
            }
            inline void setOrigin(const Raylib::Vector2& origin) {
                _origin->x = origin.x;
                _origin->y = origin.y;
            }
            inline Raylib::Rectangle getRect() const {
                return *_rect;
            }
            inline void setRect(const Raylib::Rectangle& rect) {
                _rect->x = rect.x;
                _rect->y = rect.y;
                _rect->width = rect.width;
                _rect->height = rect.height;
            }
            inline void setRect(float x, float y, float width, float height) {
                _rect->x = x;
                _rect->y = y;
                _rect->width = width;
                _rect->height = height;
            }
            inline bool isAnimated() const {
                return _isAnimated;
            }
            inline float getWidth() {
                return _texture->getWidth();
            }
            inline float getHeight() {
                return _texture->getHeight();
            }
            inline void setAnimated(bool isAnimated) {
                _isAnimated = isAnimated;
            }
            inline void setActive(bool active) {
                _active = active;
            }
            inline bool isActive() const {
                return _active;
            }
            inline int getFrameCount() const {
                return _frameCount;
            }
            inline void setFrameCount(int frameCount) {
                _frameCount = frameCount;
            }
            inline float getFrameSpeed() const {
                return _frameSpeed;
            }
            inline void setFrameSpeed(float frameSpeed) {
                _frameSpeed = frameSpeed;
            }
            inline bool isLooped() const {
                return _isLooped;
            }
            inline void setLooped(bool isLooped) {
                _isLooped = isLooped;
            }
            inline void setTexture(const std::string& fileName) {
                _texture = std::make_unique<Raylib::Texture2D>(fileName);
            }
            inline void setTexture(const std::string& fileName, int width, int height) {
                _texture = std::make_unique<Raylib::Texture2D>(fileName, width, height);
            }
            inline void unload() {
                _texture->unload();
            }
            inline void draw(const Raylib::Vector2& position, const Raylib::Vector2& scale, const float& rotation) {
                if (_active) {
                    if (_isAnimated)
                    {
                        _frameCounter++;
                        if (_frameCounter >= 60 / _frameSpeed) {
                            _frameCounter = 0;
                            _currentFrame++;
                            if (_currentFrame > _frameCount - 1) {
                                _currentFrame = 0;
                                if (!_isLooped) {
                                    _active = false;
                                    return;
                                }
                            }
                            _rect->x = _currentFrame * _rect->width;
                        }
                        _texture->draw(*_rect, Raylib::Rectangle({position.x + _position->x, position.y + _position->y}, {_rect->width * scale.x, _rect->height * scale.y}), *_origin, rotation);
                    }
                    else{
                        _texture->draw(*_rect, Raylib::Rectangle({_position->x + _parentPos->x + _origin->x, _position->y + _parentPos->y + _origin->y}, {_rect->width * scale.x, _rect->height * scale.y}), *_origin, rotation);
                        //_texture->draw(*_position + *_parentPos, scale, rotation);
                    }
                }
				/*std::cout << "Drawing sprite" << std::endl;
				std::cout << "Position: " << _position->x << ", " << _position->y << std::endl;
				std::cout << "Entity position: " << _entityPos->x << ", " << _entityPos->y << std::endl;*/
            }
            // inline void draw(const ::Rectangle& source) {
            //     _texture->draw(_position->x, _position->y, source, WHITE);
            // }
            // inline void draw(const ::Rectangle& source, const ::Color& tint) {
            //     _texture->draw(_position->x, _position->y, source, tint);
            // }
            // inline void draw(const ::Rectangle& source, const ::Color& tint, float rotation, float scale, const ::Color& tint2) {
            //     _texture->draw(_position->x, _position->y, source, tint, rotation, scale, tint2);
            // }
            // inline void drawTextureRect() {
            //     ::DrawTextureRec(*_texture, *_rect, *_position, WHITE);
            // }
            // inline void drawTextureRect(const ::Color& tint) {
            //     ::DrawTextureRec(*_texture, *_rect, *_position, tint);
            // }
            inline bool isColliding(const std::shared_ptr<Raylib::Vector2>& position1, const std::shared_ptr<Raylib::Vector2>& position2, float hitbox) {
                return position1->distance(*position2) < hitbox;
            }
        protected:
        private:
            std::shared_ptr<Raylib::Texture2D> _texture;
            std::shared_ptr<Raylib::Vector2> _origin;
            std::shared_ptr<Raylib::Vector2> _position;
            std::shared_ptr<Raylib::Vector2> _parentPos;
            std::shared_ptr<Raylib::Rectangle> _rect;
            float _frameSpeed;
            bool _isLooped;
            bool _isAnimated;
            int _frameCount;
            int _frameCounter;
            int _currentFrame;
            bool _active;
    };
}

#endif /* !SPRITE_HPP_ */