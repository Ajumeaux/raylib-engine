/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Window
*/


#ifndef WINDOW_HPP_
#define WINDOW_HPP_


#include "Text3D.hpp"
#include "Text.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Window {
    public:
        Window(int window_width, int window_height, const std::string &window_name) {
			::InitWindow(window_width, window_height, window_name.c_str());
			::InitAudioDevice(); // Initialize audio device
            //::HideCursor();
            ::ToggleFullscreen();
			::SetExitKey(0); //this is to disable the escape key to close the window
        }
        bool shouldClose() {
            return ::WindowShouldClose();
        }
        bool isResized() {
            return ::IsWindowResized();
        }
        void close() {
            ::StopSoundMulti();
            ::CloseAudioDevice();
            ::CloseWindow();
        }
        void beginDrawing() {
            ::BeginDrawing();
        }
        void clearBackground(::Color color) {
            ::ClearBackground(color);
        }
        void endDrawing() {
            ::EndDrawing();
        }
        void drawFPS(int posx, int posy) {
            DrawFPS(posx, posy);
        }
        bool isKeyDown(int key) {
            return ::IsKeyDown(key);
        }
        float getFrameTime() {
            return ::GetFrameTime();
        }
        void setTargetFPS(int fps) {
            ::SetTargetFPS(fps);
        }
    };
};

#endif