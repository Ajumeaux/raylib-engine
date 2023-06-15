
/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RaylibEncap
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Raylib.hpp"
#include "ID.hpp"

namespace Raylib {
    class Entity
    {   public:
            Entity(const Raylib::Entity& entity) {
                _id = entity._id;
                _model = entity._model;
                _sprite = entity._sprite;
                _text = entity._text;
                _sound = entity._sound;
                _music = entity._music;
            };
            Entity(Raylib::ID id) {
                _id = id;
            };
            Entity() = default;
            ~Entity() = default;
            void unload() {
                for (auto& model : _model)
                    model->unload();
                for (auto& sprite : _sprite)
                    sprite->unload();
                for (auto& text : _text)
                    text->unload();
                for (auto& sound : _sound)
                    sound->unload();
                for (auto& music : _music)
                    music->unload();
            };
            void draw(const Raylib::Vector2& position, const Raylib::Vector2& scale, float rotation) {
                for (auto& music : _music)
                    music->update();
                for (auto& sprite : _sprite)
                    sprite->draw(position, scale, rotation);
                for (auto& text : _text)
                    text->draw(position, scale, rotation);
            };
            Raylib::ID getID() { return _id; };

            Raylib::Model& getModel(int index) { return *_model[index]; };
            Raylib::Sprite& getSprite(int index) { return *_sprite[index]; };
            Raylib::Text& getText(int index) { return *_text[index]; };
            Raylib::Sound& getSound(int index) { return *_sound[index]; };
            Raylib::Music& getMusic(int index) { return *_music[index]; };
            Raylib::Clock& getClock(int index) { return *_clock[index]; };

            std::shared_ptr<Raylib::Model> getModelPtr(int index) { return _model[index]; };
            std::shared_ptr<Raylib::Sprite> getSpritePtr(int index) { return _sprite[index]; };
            std::shared_ptr<Raylib::Text> getTextPtr(int index) { return _text[index]; };
            std::shared_ptr<Raylib::Sound> getSoundPtr(int index) { return _sound[index]; };
            std::shared_ptr<Raylib::Music> getMusicPtr(int index) { return _music[index]; };
            std::shared_ptr<Raylib::Clock> getClockPtr(int index) { return _clock[index]; };

            std::vector<std::shared_ptr<Raylib::Model>>& getModelList() { return _model; };
            std::vector<std::shared_ptr<Raylib::Sprite>>& getSpriteList() { return _sprite; };
            std::vector<std::shared_ptr<Raylib::Text>>& getTextList() { return _text; };
            std::vector<std::shared_ptr<Raylib::Sound>>& getSoundList() { return _sound; };
            std::vector<std::shared_ptr<Raylib::Music>>& getMusicList() { return _music; };
            std::vector<std::shared_ptr<Raylib::Clock>>& getClockList() { return _clock; };

			std::shared_ptr< std::vector<std::shared_ptr<Raylib::Model>>> getModelListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Model>>>(_model); };
			std::shared_ptr< std::vector<std::shared_ptr<Raylib::Sprite>>> getSpriteListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Sprite>>>(_sprite); };
			std::shared_ptr< std::vector<std::shared_ptr<Raylib::Text>>> getTextListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Text>>>(_text); };
			std::shared_ptr< std::vector<std::shared_ptr<Raylib::Sound>>> getSoundListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Sound>>>(_sound); };
			std::shared_ptr< std::vector<std::shared_ptr<Raylib::Music>>> getMusicListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Music>>>(_music); };
            std::shared_ptr< std::vector<std::shared_ptr<Raylib::Clock>>> getClockListPtr() { return std::make_shared<std::vector<std::shared_ptr<Raylib::Clock>>>(_clock); };

            void addModel(Raylib::Model model) { _model.push_back(std::make_shared<Raylib::Model>(model)); };
            void addSprite(Raylib::Sprite sprite) { _sprite.push_back(std::make_shared<Raylib::Sprite>(sprite)); };
            void addText(Raylib::Text text) { _text.push_back(std::make_shared<Raylib::Text>(text)); };
            void addSound(Raylib::Sound sound) { _sound.push_back(std::make_shared<Raylib::Sound>(sound)); };
            void addMusic(Raylib::Music music) { _music.push_back(std::make_shared<Raylib::Music>(music)); };
            void addClock(Raylib::Clock clock) { _clock.push_back(std::make_shared<Raylib::Clock>(clock)); };

            void addModel(std::string modelPath) {
                (void)modelPath; // TODO
            };
            void addSprite(std::string spritePath) {
				_sprite.push_back(std::make_shared<Raylib::Sprite>(spritePath, Raylib::Vector2(0, 0), Raylib::Vector2(0, 0), Raylib::Vector2(0, 0)));
            };
            void addSprite(std::string spritePath, const Raylib::Vector2& position, const Raylib::Vector2& origin, const Raylib::Vector2& parentPos) {
                _sprite.push_back(std::make_shared<Raylib::Sprite>(spritePath, position, origin, parentPos));
            };
            void addText(std::string text, int fontSize) { _text.push_back(std::make_shared<Raylib::Text>(text, fontSize)); };
            void addSound(std::string soundPath) { _sound.push_back(std::make_shared<Raylib::Sound>(soundPath)); };
            void addMusic(std::string musicPath) { _music.push_back(std::make_shared<Raylib::Music>(musicPath)); };
            void addClock() { _clock.push_back(std::make_shared<Raylib::Clock>()); };

			void setParentPos(const Raylib::Vector2& parentPos) {
				for (auto& sprite : _sprite)
					sprite->setParentPos(parentPos);
			};

            void setID() {
                _id = Raylib::ID(static_cast<int>(_model.size()), static_cast<int>(_sprite.size()), static_cast<int>(_text.size()), static_cast<int>(_sound.size()), static_cast<int>(_music.size()), static_cast<int>(_clock.size()), char (rand() % 26 + 65));
            }
            void setIDPtr() {
                _id = Raylib::ID(reinterpret_cast<std::uintptr_t>(this));
            }
            void setVolume(float volume) {
                for (auto& sound : _sound)
                    sound->setVolume(volume);
                for (auto& music : _music)
                    music->setVolume(volume);
            }
            void pause() {
                for (auto& sound : _sound)
                    sound->pause();
                for (auto& music : _music)
                    music->pause();
                for (auto& clock : _clock)
                    clock->pause();
            }
            void resume() {
                for (auto& sound : _sound)
                    sound->resume();
                for (auto& music : _music)
                    music->resume();
                for (auto& clock : _clock)
                    clock->resume();
            }
            void playMusic(int index) {
                if (index < 0 || index >= static_cast<int>(_music.size()))
                    return;
                _music[index]->play();
            }
            void playSound(int index) {
                if (index < 0 || index >= static_cast<int>(_sound.size()))
                    return;
                _sound[index]->play();
            }
            void pauseMusic(int index) {
                if (index < 0 || index >= static_cast<int>(_music.size()))
                    return;
                _music[index]->pause();
            }
            void pauseSound(int index) {
                if (index < 0 || index >= static_cast<int>(_sound.size()))
                    return;
                _sound[index]->pause();
            }
            void stopMusic(int index) {
                if (index < 0 || index >= static_cast<int>(_music.size()))
                    return;
                _music[index]->stop();
            }
            void stopSound(int index) {
                if (index < 0 || index >= static_cast<int>(_sound.size()))
                    return;
                _sound[index]->stop();
            }
            void stopAllMusic() {
                for (auto& music : _music)
                    music->stop();
            }
            void stopAllSound() {
                for (auto& sound : _sound)
                    sound->stop();
            }
            void stopAll() {
                stopAllMusic();
                stopAllSound();
            }
        private:
            std::vector<std::shared_ptr<Raylib::Model>> _model;
            std::vector<std::shared_ptr<Raylib::Sprite>> _sprite;
            std::vector<std::shared_ptr<Raylib::Text>> _text;
            std::vector<std::shared_ptr<Raylib::Sound>> _sound;
            std::vector<std::shared_ptr<Raylib::Music>> _music;
            std::vector<std::shared_ptr<Raylib::Clock>> _clock;
            Raylib::ID _id;
    };
}

#endif /* !ENTITY_HPP_ */
