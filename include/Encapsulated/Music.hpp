/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Music : public ::Music {
    public:
        Music(const std::string& fileName) {
            ::Music music = LoadMusicStream(fileName.c_str());
            ctxType = music.ctxType;
            ctxData = music.ctxData;
            looping = music.looping;
            frameCount = music.frameCount;
            stream = music.stream;
        }
        inline void unload() {
            //::UnloadMusicStream(*this);
        }
        inline void play() {
            ::PlayMusicStream(*this);
        }
        inline void update() {
            ::UpdateMusicStream(*this);
        }
        inline void stop() {
            ::StopMusicStream(*this);
        }
        inline void pause() {
            ::PauseMusicStream(*this);
        }
        inline void resume() {
            ::ResumeMusicStream(*this);
        }
        inline void seek(float position) {
            SeekMusicStream(*this, position);
        }
        inline bool isplaying() const {
            return ::IsMusicStreamPlaying(*this);
        }
        inline void setVolume(float volume) {
            ::SetMusicVolume(*this, volume);
        }
        inline void setpitch(float pitch) {
            ::SetMusicPitch(*this, pitch);
        }
        inline float gettimelength() const {
            return ::GetMusicTimeLength(*this);
        }
        inline float gettimeplayed() const {
            return ::GetMusicTimePlayed(*this);
        }
    };
}

#endif