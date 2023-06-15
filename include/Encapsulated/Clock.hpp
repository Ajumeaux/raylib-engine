/*
** EPITECH PROJECT, 2023
** game
** File description:
** Camera
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

using namespace OriginalRaylib;

namespace Raylib {
    class Clock {
    public:
        Clock() {
            _running = false;
        }
        Clock(float time) {
            _running = false;
            _start = std::chrono::system_clock::now();
            _end = _start + std::chrono::milliseconds(static_cast<int>(time));
        }
        ~Clock() = default;
        void start() {
            _start = std::chrono::system_clock::now();
            _running = true;
        }
        void stop() {
            _end = std::chrono::system_clock::now();
            _running = false;
        }
        void reset() {
            _running = false;
        }
        float getElapsedTime() {
            if (_running)
                _end = std::chrono::system_clock::now();
            return static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count());
        }
        bool isItTime() {
            if (_running)
                _end = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() >= 0;
        }
        float getElapsedTimeMicroseconds() {
            if (_running)
                _end = std::chrono::system_clock::now();
            return static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count());
        }
        bool isRunning() {
            return _running;
        }
        bool pause() {
            if (_running) {
                _end = std::chrono::system_clock::now();
                _running = false;
                return true;
            }
            return false;
        }
        bool resume() {
            if (!_running) {
                _start = std::chrono::system_clock::now();
                _running = true;
                return true;
            }
            return false;
        }
    private:
        std::chrono::time_point<std::chrono::system_clock> _start;
        std::chrono::time_point<std::chrono::system_clock> _end;
        bool _running;
    };
}

#endif