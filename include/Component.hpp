
/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RaylibEncap
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "./Entity.hpp"

namespace Raylib
{
    class Component
    {
    public:
        Component()
        {
            _position = std::make_shared<Raylib::Vector2>(0, 0);
            _scale = std::make_shared<Raylib::Vector2>(1, 1);
            _rotation = 0;
            _input = std::make_shared<Raylib::Input>();
            _active = true;
            _sceneActive = std::make_shared<bool>(true);
        }
        Component(Raylib::Vector2 position, Raylib::Vector2 scale, float rotation)
        {
            _position = std::make_shared<Raylib::Vector2>(position);
            _scale = std::make_shared<Raylib::Vector2>(scale);
            _rotation = rotation;
            _input = std::make_shared<Raylib::Input>();
            _active = true;
            _sceneActive = std::make_shared<bool>(true);
        }
        Component(std::shared_ptr<Raylib::Entity> entity)
        {
            _entity = entity;
            _position = std::make_shared<Raylib::Vector2>(0, 0);
            _scale = std::make_shared<Raylib::Vector2>(1, 1);
            _rotation = 0;
            _input = std::make_shared<Raylib::Input>();
            _active = true;
            _sceneActive = std::make_shared<bool>(true);
        }
        Component(const Component &cpy)
        {
            _entity = cpy._entity;
            _position = cpy._position;
            _scale = cpy._scale;
            _rotation = cpy._rotation;
            _input = cpy._input;
            _active = cpy._active;
            _sceneActive = cpy._sceneActive;
        }
        ~Component() = default;
        void draw()
        {
            if (_active)
                _entity->draw(*_position, *_scale, _rotation);
        }
        virtual void update() = 0;
        void setActive(bool active)
        {
            _active = active;
        }
        bool getActive()
        {
            return _active;
        }
        void setEntity(Raylib::Entity entity)
        {
            _entity = std::make_shared<Raylib::Entity>(entity);
        }
        inline float getSpriteWidth(int sprite)
        {
            return (*_entity->getSpriteListPtr())[sprite]->getWidth();
        }
        inline float getSpriteWidthScaled(int sprite)
        {
            return (*_entity->getSpriteListPtr())[sprite]->getWidth() * _scale->x;
        }
        inline float getSpriteHeight(int sprite)
        {
            return (*_entity->getSpriteListPtr())[sprite]->getHeight();
        }
        inline float getSpriteHeightScaled(int sprite)
        {
            return (*_entity->getSpriteListPtr())[sprite]->getHeight() * _scale->y;
        }
        std::shared_ptr<Raylib::Entity> getEntity()
        {
            return _entity;
        }
        std::shared_ptr<Raylib::Vector2> getPosition()
        {
            return _position;
        }
        void setScale(int x, int y)
        {
            _scale->x = (float)x;
            _scale->y = (float)y;
        }
        void setScale(const Raylib::Vector2 &scale)
        {
            _scale->x = scale.x;
            _scale->y = scale.y;
        }
        void setScale(std::shared_ptr<Raylib::Vector2> scale)
        {
            _scale = scale;
        }
        std::shared_ptr<Raylib::Vector2> getScale()
        {
            return _scale;
        }
        void setRotation(float rotation)
        {
            _rotation = rotation;
        }
        void setVolume(float volume)
        {
            _entity->setVolume(volume);
        }
        void playMusic(int music)
        {
            _entity->playMusic(music);
        }
        void playSound(int sound)
        {
            _entity->playSound(sound);
        }
        void pauseMusic(int music)
        {
            _entity->pauseMusic(music);
        }
        void pauseSound(int sound)
        {
            _entity->pauseSound(sound);
        }
        void setSceneActive(std::shared_ptr<bool> sceneActive)
        {
            _sceneActive = std::move(sceneActive);
        }
        float getRotation()
        {
            return _rotation;
        }
        virtual Raylib::Rectangle getHitbox()
        {
            return Raylib::Rectangle({_position->x, _position->y}, {getSpriteWidthScaled(0), getSpriteHeightScaled(0)});
        }
        virtual bool checkCollision(Raylib::Rectangle otherHitbox)
        {
            Raylib::Rectangle myHitbox = getHitbox();
            return (myHitbox.checkCollision(otherHitbox));
        }
        bool isMouseHovering()
        {
            Raylib::Rectangle myHitbox = getHitbox();
            return (myHitbox.checkCollision(Raylib::Rectangle(_input->getMousePosition(), {1, 1})));
        }
        void setInput(std::shared_ptr<Raylib::Input> input)
        {
            _input = std::move(input);
        }
        void pause()
        {
            _entity->pause();
        }
        void resume()
        {
            _entity->resume();
        }
        bool pause(Raylib::ID id)
        {
            if (_entity->getID() == id)
            {

                _entity->pause();
                return true;
            }
            else
            {
                return false;
            }
        }
        void addSprite(std::string path)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addSprite(path);
        }
        void addSprite(std::string spritePath, const Raylib::Vector2 &position, const Raylib::Vector2 &origin)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addSprite(spritePath, position, origin, *_position);
        }
        void addSprite(Raylib::Sprite sprite)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addSprite(sprite);
        }
        void addModel(std::string path)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addModel(path);
        }
        void addSound(std::string path)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addSound(path);
        }
        void addMusic(std::string path)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addMusic(path);
        }
        void addText(std::string text, int fontSize)
        {
            if (_entity == nullptr)
                _entity = std::make_shared<Raylib::Entity>();
            _entity->addText(text, fontSize);
        }
        int getTextWidth(int index)
        {
            return _entity->getText(index).getTextWidth();
        }
        void unload()
        {
            _entity->unload();
        }
        void setPosition(const Raylib::Vector2 &position)
        {
            _position->x = position.x;
            _position->y = position.y;
            _entity->setParentPos(*_position);
        }
        void setSceneActivity(bool active)
        {
            *_sceneActive = active;
        }

    protected:
        std::shared_ptr<Raylib::Entity> _entity;
        std::shared_ptr<Raylib::Vector2> _position;
        std::shared_ptr<Raylib::Vector2> _scale;
        float _rotation;
        bool _active;
        std::shared_ptr<bool> _sceneActive;
        std::shared_ptr<Raylib::Input> _input;

    private:
    };
}

#endif /* !COMPONENT_HPP_ */