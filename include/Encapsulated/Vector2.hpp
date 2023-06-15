/*
** EPITECH PROJECT, 2023
** game
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include "BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Vector2 : public ::Vector2 {
        public:
            Vector2() = default;
            Vector2(float x, float y) : ::Vector2{x, y} {}
			Vector2(int x, int y) : ::Vector2{ (float)x, (float)y } {}
            ~Vector2() = default;
            inline float getX() const {
                return x;
            }
            inline float getY() const {
                return y;
            }
            inline void setX(float x) {
                this->x = x;
            }
            inline void setY(float y) {
                this->y = y;
            }
            inline void set(float x, float y) {
                this->x = x;
                this->y = y;
            }
            inline void setZero() {
                x = 0;
                y = 0;
            }
            inline void setOne() {
                x = 1;
                y = 1;
            }
            inline void add(const Vector2 &v) {
                x += v.x;
                y += v.y;
            }
            inline void substract(const Vector2 &v) {
                x -= v.x;
                y -= v.y;
            }
            inline void multiply(const Vector2 &v) {
                x *= v.x;
                y *= v.y;
            }
            inline void divide(const Vector2 &v) {
                x /= v.x;
                y /= v.y;
            } 
            inline Vector2 operator=(void* v) {
                if (v == nullptr)
                    return *this;
                if (!reinterpret_cast<Vector2 *>(v)->x && !reinterpret_cast<Vector2 *>(v)->y)
                    return *this;
                x = reinterpret_cast<Vector2 *>(v)->x;
                y = reinterpret_cast<Vector2 *>(v)->y;
                return *this;
            }
            inline Vector2 operator+(const Vector2 &v) const {
                return Vector2(x + v.x, y + v.y);
            }
            inline Vector2 operator-(const Vector2 &v) const {
                return Vector2(x - v.x, y - v.y);
            }
            inline Vector2 operator*(const Vector2 &v) const {
                return Vector2(x * v.x, y * v.y);
            }
            inline Vector2 operator/(const Vector2 &v) const {
                return Vector2(x / v.x, y / v.y);
            }
            inline Vector2 operator+(float scalar) const {
                return Vector2(x + scalar, y + scalar);
            }
            inline Vector2 operator-(float scalar) const {
                return Vector2(x - scalar, y - scalar);
            }
            inline Vector2 operator*(float scalar) const {
                return Vector2(x * scalar, y * scalar);
            }
            inline Vector2 operator/(float scalar) const {
                return Vector2(x / scalar, y / scalar);
            }
            inline Vector2 &operator+=(const Vector2 &v) {
                x += v.x;
                y += v.y;
                return *this;
            }
            inline Vector2 &operator-=(const Vector2 &v) {
                x -= v.x;
                y -= v.y;
                return *this;
            }
            inline Vector2 &operator*=(const Vector2 &v) {
                x *= v.x;
                y *= v.y;
                return *this;
            }
            inline Vector2 &operator/=(const Vector2 &v) {
                x /= v.x;
                y /= v.y;
                return *this;
            }
            inline Vector2 &operator+=(float scalar) {
                x += scalar;
                y += scalar;
                return *this;
            }
            inline Vector2 &operator-=(float scalar) {
                x -= scalar;
                y -= scalar;
                return *this;
            }
            inline Vector2 &operator*=(float scalar) {
                x *= scalar;
                y *= scalar;
                return *this;
            }
            inline Vector2 &operator/=(float scalar) {
                x /= scalar;
                y /= scalar;
                return *this;
            }
            inline bool operator==(const Vector2 &v) const {
                return x == v.x && y == v.y;
            }
            inline bool operator!=(const Vector2 &v) const {
                return x != v.x || y != v.y;
            }
            inline bool operator==(float scalar) const {
                return x == scalar && y == scalar;
            }
            inline bool operator!=(float scalar) const {
                return x != scalar || y != scalar;
            }
            inline float dotProduct(const Vector2 &v) const {
                return x * v.x + y * v.y;
            }
            inline float crossProduct(const Vector2 &v) const {
                return x * v.y - y * v.x;
            }
            inline float length() const {
                return sqrt(x * x + y * y);
            }
            inline float lengthSqr() const {
                return x * x + y * y;
            }
            inline float distance(const Vector2 &v) const {
                return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
            }
            inline float distanceSqr(const Vector2 &v) const {
                return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
            }
            inline float angle(const Vector2 &v) const {
                return atan2(crossProduct(v), dotProduct(v));
            }
            inline Vector2 &normalize() {
                float len = length();
                if (len != 0) {
                    x /= len;
                    y /= len;
                }
                return *this;
            }
            inline Vector2 &rotate(float angle) {
                float cos = cosf(angle);
                float sin = sinf(angle);
                float rx = x * cos - y * sin;
                float ry = x * sin + y * cos;
                x = rx;
                y = ry;
                return *this;
            }
            inline Vector2 &lerp(const Vector2 &v, float amount) {
                x += (v.x - x) * amount;
                y += (v.y - y) * amount;
                return *this;
            }
            inline Vector2 &reflect(const Vector2 &normal) {
                float dot = dotProduct(normal);
                x -= (2 * dot) * normal.x;
                y -= (2 * dot) * normal.y;
                return *this;
            }
            inline Vector2 &min(const Vector2 &v) {
                x = x < v.x ? x : v.x;
                y = y < v.y ? y : v.y;
                return *this;
            }
            inline Vector2 &max(const Vector2 &v) {
                x = x > v.x ? x : v.x;
                y = y > v.y ? y : v.y;
                return *this;
            }
            inline Vector2 &clamp(const Vector2 &min, const Vector2 &max) {
                x = x < min.x ? min.x : (x > max.x ? max.x : x);
                y = y < min.y ? min.y : (y > max.y ? max.y : y);
                return *this;
            }
            inline Vector2 &clamp(float min, float max) {
                x = x < min ? min : (x > max ? max : x);
                y = y < min ? min : (y > max ? max : y);
                return *this;
            }
            inline Vector2 &clamp01() {
                x = x < 0 ? 0 : (x > 1 ? 1 : x);
                y = y < 0 ? 0 : (y > 1 ? 1 : y);
                return *this;
            }
            inline Vector2 &abs() {
                x = x < 0 ? -x : x;
                y = y < 0 ? -y : y;
                return *this;
            }
            inline Vector2 &negate() {
                x = -x;
                y = -y;
                return *this;
            }
            inline Vector2 &floor() {
                x = std::floor(x);
                y = std::floor(y);
                return *this;
            }
            inline Vector2 &ceil() {
                x = std::ceil(x);
                y = std::ceil(y);
                return *this;
            }
            inline Vector2 &round() {
                x = std::round(x);
                y = std::round(y);
                return *this;
            }
            inline Vector2 &trunc() {
                x = std::trunc(x);
                y = std::trunc(y);
                return *this;
            }
            inline Vector2 &fract() {
                x = x - std::floor(x);
                y = y - std::floor(y);
                return *this;
            }
            inline Vector2 &mod(float scalar) {
                x = std::fmod(x, scalar);
                y = std::fmod(y, scalar);
                return *this;
            }
            inline Vector2 &mod(const Vector2 &v) {
                x = std::fmod(x, v.x);
                y = std::fmod(y, v.y);
                return *this;
            }
            inline Vector2 &step(const Vector2 &edge) {
                x = x < edge.x ? (float)0 : 1;
                y = y < edge.y ? (float)0 : 1;
                return *this;
            }   
            inline Vector2 &step(float edge) {
                x = x < edge ? (float)0 : 1;
                y = y < edge ? (float)0 : 1;
                return *this;
            }
            inline Vector2 &zero() {
                x = 0;
                y = 0;
                return *this;
            }
            inline Vector2 &one() {
                x = 1;
                y = 1;
                return *this;
            }
            inline Vector2 &up() {
                x = 0;
                y = 1;
                return *this;
            }
            inline Vector2 &down() {
                x = 0;
                y = -1;
                return *this;
            }
            inline Vector2 &left() {
                x = -1;
                y = 0;
                return *this;
            }
            inline Vector2 &right() {
                x = 1;
                y = 0;
                return *this;
            }
            inline Vector2 &add_gravity_to_object(float mass, float gravity) {
                y += mass * gravity;
                return *this;
            }
            inline Vector2 &add_gravity_to_object(float mass, const Vector2 &gravity) {
                x += mass * gravity.x;
                y += mass * gravity.y;
                return *this;
            }
            inline Vector2 &add_gravity_to_object(const Vector2 &mass, float gravity) {
                x += mass.x * gravity;
                y += mass.y * gravity;
                return *this;
        }
    };
}

#endif /* !VECTOR2_HPP_ */

