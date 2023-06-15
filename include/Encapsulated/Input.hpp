/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#pragma once

#include "./BaseRaylib.hpp"
#include <vector>
#include <array>

using namespace OriginalRaylib;

#define MAX_KEYS 5 // Nombre maximum de touches pour chaque action

namespace Raylib {
    enum Inputs {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3,
        ACTION = 4,
        ACTION2 = 5,
        ACTION3 = 6,
        ACTION4 = 7,
        SELECT = 8,
        START = 9,
    };

    class Input {
        public:
            Input() {
                keys[UP].push_back(OriginalRaylib::KEY_UP);
                controllerKeys[UP].push_back(OriginalRaylib::GAMEPAD_BUTTON_LEFT_FACE_UP);
                keys[DOWN].push_back(OriginalRaylib::KEY_DOWN);
                controllerKeys[DOWN].push_back(OriginalRaylib::GAMEPAD_BUTTON_LEFT_FACE_DOWN);
                keys[LEFT].push_back(OriginalRaylib::KEY_LEFT);
                controllerKeys[LEFT].push_back(OriginalRaylib::GAMEPAD_BUTTON_LEFT_FACE_LEFT);
                keys[RIGHT].push_back(OriginalRaylib::KEY_RIGHT);
                controllerKeys[RIGHT].push_back(OriginalRaylib::GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
                keys[ACTION].push_back(OriginalRaylib::KEY_SPACE);
                controllerKeys[ACTION].push_back(OriginalRaylib::GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
                keys[START].push_back(OriginalRaylib::KEY_ESCAPE);
                controllerKeys[START].push_back(OriginalRaylib::GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
                keys[SELECT].push_back(OriginalRaylib::KEY_ENTER);
                textInputEnabled = false;
                currentTextInput = 0;
                textInput.push_back(std::string(""));
                maxTextInputLength.push_back(1000000);
            }

            void update() {
                if (textInputEnabled) {
                    for (int i = 0; i < 10; i++) {
                        actionsPressed[i] = false;
                        actionsDown[i] = false;
                    }
                    currentCharacter = OriginalRaylib::GetCharPressed();
                    currentKey = OriginalRaylib::GetKeyPressed();
                    
                    // if caracter is egal to keys[SELECT] or keys[START] then stopTextInput
                    for (auto key : keys[SELECT]) {
                        if (currentKey == key) {
                            stopTextInput();
                            break;
                        }
                    }
                    for (auto key : keys[START]) {
                        if (currentKey == key) {
                            stopTextInput();
                            break;
                        }
                    }
                    if (OriginalRaylib::IsGamepadAvailable(0)) {
                        for (auto key : controllerKeys[SELECT]) {
                            if (OriginalRaylib::IsGamepadButtonPressed(0, key)) {
                                stopTextInput();
                                break;
                            }
                        }
                        for (auto key : controllerKeys[START]) {
                            if (OriginalRaylib::IsGamepadButtonPressed(0, key)) {
                                stopTextInput();
                                break;
                            }
                        }
                    }
                    if (previousKey == OriginalRaylib::KEY_LEFT_CONTROL || previousKey == OriginalRaylib::KEY_RIGHT_CONTROL) {
                        if (currentKey == OriginalRaylib::KEY_V && textInput[currentTextInput].length() + std::string(OriginalRaylib::GetClipboardText()).length() < maxTextInputLength[currentTextInput]) {
                            textInput[currentTextInput] += OriginalRaylib::GetClipboardText();
                        }
                    } else if (currentCharacter >= 32 && textInput[currentTextInput].length() < maxTextInputLength[currentTextInput]) {
                        textInput[currentTextInput] += static_cast<char>(currentCharacter);
                    } else if (currentKey == OriginalRaylib::KEY_BACKSPACE && textInput[currentTextInput].length() > 0) {
                        textInput[currentTextInput].pop_back();
                    }
                    if (previousKey != currentKey && currentKey != 0)
                        previousKey = currentKey;
                } else {
                    for (int i = 0; i < 10; i++) {
                        actionsPressed[i] = false;
                        actionsDown[i] = false;
                        for (auto key : keys[i]) {
                            if (OriginalRaylib::IsKeyPressed(key)) {
                                actionsPressed[i] = true;
                                break;
                            }
                        }
                        for (auto key : keys[i]) {
                            if (OriginalRaylib::IsKeyDown(key)) {
                                actionsDown[i] = true;
                                break;
                            }
                        }
                        if (OriginalRaylib::IsGamepadAvailable(0)) {
                            if (i == LEFT && OriginalRaylib::GetGamepadAxisMovement(0, OriginalRaylib::GAMEPAD_AXIS_LEFT_X) < -0.5f)
                                actionsDown[i] = true;
                            if (i == RIGHT && OriginalRaylib::GetGamepadAxisMovement(0, OriginalRaylib::GAMEPAD_AXIS_LEFT_X) > 0.5f)
                                actionsDown[i] = true;
                            if (i == UP && OriginalRaylib::GetGamepadAxisMovement(0, OriginalRaylib::GAMEPAD_AXIS_LEFT_Y) < -0.5f)
                                actionsDown[i] = true;
                            if (i == DOWN && OriginalRaylib::GetGamepadAxisMovement(0, OriginalRaylib::GAMEPAD_AXIS_LEFT_Y) > 0.5f)
                                actionsDown[i] = true;
                            for (auto key : controllerKeys[i]) {
                                if (OriginalRaylib::IsGamepadButtonPressed(0, key)) {
                                    actionsPressed[i] = true;
                                    break;
                                }
                            }
                            for (auto key : controllerKeys[i]) {
                                if (OriginalRaylib::IsGamepadButtonDown(0, key)) {
                                    actionsDown[i] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            void startTextInput(int index) {
                currentTextInput = index;
                textInputEnabled = true;
            }

            void stopTextInput() {
                textInputEnabled = false;
            }

            bool isTextInputEnabled() const {
                return textInputEnabled;
            }

            void setNumberTextInput(int number) {
                textInput.clear();
                for (int i = 0; i < number; i++) {
                    textInput.push_back(std::string(""));
                    maxTextInputLength.push_back(1000000);
                }
            }

            void addTextInput() {
                textInput.push_back(std::string(""));
            }

            int getNumberTextInput() const {
                return textInput.size();
            }

            void setTextInput(std::string text, int index) {
                textInput[index] = text;
            }

            std::string getTextInput(int index) const {
                return textInput[index];
            }

            void clearTextInput() {
                textInput.clear();
            }

            void setMaxTextInputLength(int length, int index) {
                maxTextInputLength[index] = length;
            }

            int getMaxTextInputLength(int index) const {
                return maxTextInputLength[index];
            }

            bool isLeftMousePressed() const {
                return OriginalRaylib::IsMouseButtonPressed(OriginalRaylib::MOUSE_LEFT_BUTTON);
            }

            bool isLeftMouseDown() const {
                return OriginalRaylib::IsMouseButtonDown(OriginalRaylib::MOUSE_LEFT_BUTTON);
            }

            bool isLeftMouseReleased() const {
                return OriginalRaylib::IsMouseButtonReleased(OriginalRaylib::MOUSE_LEFT_BUTTON);
            }

            bool isRightMousePressed() const {
                return OriginalRaylib::IsMouseButtonPressed(OriginalRaylib::MOUSE_RIGHT_BUTTON);
            }

            bool isRightMouseDown() const {
                return OriginalRaylib::IsMouseButtonDown(OriginalRaylib::MOUSE_RIGHT_BUTTON);
            }

            bool isRightMouseReleased() const {
                return OriginalRaylib::IsMouseButtonReleased(OriginalRaylib::MOUSE_RIGHT_BUTTON);
            }

            bool isMiddleMousePressed() const {
                return OriginalRaylib::IsMouseButtonPressed(OriginalRaylib::MOUSE_MIDDLE_BUTTON);
            }

            bool isMiddleMouseDown() const {
                return OriginalRaylib::IsMouseButtonDown(OriginalRaylib::MOUSE_MIDDLE_BUTTON);
            }

            bool isMiddleMouseReleased() const {
                return OriginalRaylib::IsMouseButtonReleased(OriginalRaylib::MOUSE_MIDDLE_BUTTON);
            }

            Vector2 getMousePosition() const {
                return Vector2(OriginalRaylib::GetMousePosition().x, OriginalRaylib::GetMousePosition().y);
            }

            void setMousePosition(Vector2 position) {
                OriginalRaylib::SetMousePosition(position.x, position.y);
            }

            void MoveMouseToBottomLeft() {
                OriginalRaylib::SetMousePosition(WINDOW_WIDTH, WINDOW_HEIGHT);
            }

            void hideMouse() {
                OriginalRaylib::HideCursor();
            }

            void showMouse() {
                OriginalRaylib::ShowCursor();
            }

            int getMouseWheelMove() const {
                return OriginalRaylib::GetMouseWheelMove();
            }

            bool isActionPressed(Inputs input) const {
                return actionsPressed[input];
            }

            bool isActionReleased(Inputs input) const {
                return !actionsPressed[input];
            }

            bool isActionDown(Inputs input) const {
                return actionsDown[input];
            }

            void setKey(Inputs input, int key) {
                keys[input].clear();
                keys[input].push_back(key);
            }

            void addKey(Inputs input, int key) {
                keys[input].push_back(key);
            }

            void removeKey(Inputs input, int key) {
                auto it = std::find(keys[input].begin(), keys[input].end(), key);
                if (it != keys[input].end()) {
                    keys[input].erase(it);
                }
            }

            void setControllerKey(Inputs input, int key) {
                controllerKeys[input].clear();
                controllerKeys[input].push_back(key);
            }

            void addControllerKey(Inputs input, int key) {
                controllerKeys[input].push_back(key);
            }

            void removeControllerKey(Inputs input, int key) {
                auto it = std::find(controllerKeys[input].begin(), controllerKeys[input].end(), key);
                if (it != controllerKeys[input].end()) {
                    controllerKeys[input].erase(it);
                }
            }

        private:
            std::vector<int> keys[10];
            std::vector<int> controllerKeys[10];
            bool actionsPressed[10];
            bool actionsDown[10];
            bool textInputEnabled;
            int currentTextInput;
            std::vector<std::string> textInput;
            std::vector<int> maxTextInputLength;
            int previousKey;
            int currentKey;
            int currentCharacter;
    };
}

#endif //INPUT