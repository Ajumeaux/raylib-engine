/*
** EPITECH PROJECT, 2023
** game
** File description:
** ID
*/

#ifndef ID_HPP_
#define ID_HPP_

#include "./Encapsulated/BaseRaylib.hpp"

namespace Raylib {
    class ID {
    public:
            ID() {
            _id = std::vector<char>(8);
            for (int i = 0; i < 8; i++) {
                _id[i] = (char)OriginalRaylib::GetRandomValue(0, 255);
            }
        }
            ID(std::uintptr_t id) {
            _id = std::vector<char>(8);
                for (int i = 0; i < 8; i++) {
                _id[i] = (char)id;
                id >>= 8;
            }
        }
            ID(int modelSize, int spriteSize, int textSize, int soundSize, int musicSize, int clockSize, int c) {
            _id = std::vector<char>(8);
            _id[0] = (char)modelSize;
            _id[1] = (char)spriteSize;
            _id[2] = (char)textSize;
            _id[3] = (char)soundSize;
            _id[4] = (char)musicSize;
            _id[5] = (char)clockSize;
            _id[6] = c;
                _id[7] = (char)GetRandomValue(0, 255);
        }
            ID(const ID &id) {
            _id = id._id;
        }
        ~ID() = default;
            ID &operator=(const ID &id) {
            _id = id._id;
            return *this;
        }
            bool operator==(const ID &id) const {
                for (int i = 0; i < 8; i++) {
                if (_id[i] != id._id[i])
                    return false;
            }
            return true;
        }
            bool operator!=(const ID &id) const {
                for (int i = 0; i < 8; i++) {
                if (_id[i] != id._id[i])
                    return true;
            }
            return false;
        }
    private:
        std::vector<char> _id;
    };
}

#endif /* !ID_HPP_ */