/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Sound : public ::Sound {
    public:
        Sound(const std::string& fileName) {
            ::Sound sound = ::LoadSound(fileName.c_str());
            frameCount = sound.frameCount;
            stream = sound.stream;
        }
        inline void unload() {
            //::UnloadSound(*this);
        }
        inline void play() {
            ::PlaySoundMulti(*this);
        }
        inline void stop() {
            ::StopSound(*this);
        }
        inline void pause() {
            ::PauseSound(*this);
        }
        inline void resume() {
            ::ResumeSound(*this);
        }
        inline bool isPlaying() const {
            return ::IsSoundPlaying(*this);
        }
        inline void setVolume(float volume) {
            ::SetSoundVolume(*this, volume);
        }
        inline void setPitch(float pitch) {
            ::SetSoundPitch(*this, pitch);
        }
    };
}

#endif