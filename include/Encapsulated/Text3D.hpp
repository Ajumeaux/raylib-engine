/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Text3D
*/

#pragma once

#include "Model.hpp"

using namespace OriginalRaylib;

enum Alphabet {
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 14,
    F = 15,
    G = 16,
    H = 17,
    I = 18,
    J = 19,
    K = 20,
    L = 21,
    M = 22,
    N = 23,
    O = 24,
    P = 25,
    Q = 26,
    R = 27,
    S = 28,
    T = 29,
    U = 30,
    V = 31,
    W = 32,
    X = 33,
    Y = 34,
    Z = 35
};

namespace Raylib {
    class Text3D {
    public:
        Text3D() {
            std::string path = "assets/models/Alphabet/";
            for (int i = 0; i < 10; ++i) {
                _alphabet.push_back(std::make_unique<Raylib::Model>(path + std::to_string(i) + "Digit.obj", "assets/textures/white.png"));
            }
            for (int i = 0; i < 26; ++i) {
                _alphabet.push_back(std::make_unique<Raylib::Model>(path + (char)(i + 65) + "Letter.obj", "assets/textures/white.png"));
            }
        }
        /*void draw(std::string text, ::Vector3 pos, ::Color color) {
            std::transform(text.begin(), text.end(), text.begin(), ::toupper);
            pos.x -= (text.length() * 0.8) / 2;
            if (!std::regex_match (text, std::regex("[A-Z 0-9]+")))
                text = "ERROR";
            for (int i = 0; text[i]; ++i) {
                if (text[i] >= 'A' && text[i] <= 'Z') {
                    _alphabet[text[i] - 55]->draw(pos, 1, color);
                }
                else if (text[i] >= '0' && text[i] <= '9') {
                    _alphabet[text[i] - '0']->draw(pos, 1, color);
                }
                else if (text[i] == ' ')
                    pos.x += 0.3f;
                pos.x += 0.5f;
            }
        }*/
    protected:
    private:
        std::vector<std::unique_ptr<Raylib::Model>> _alphabet;
    };
}

