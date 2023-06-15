/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Shader
*/

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include "./BaseRaylib.hpp"
#include "Lights.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Shader : public ::Shader {
    public:
        Shader(const std::string& fsFileName) {
            ::Shader shader = ::LoadShader(0, TextFormat(fsFileName.c_str(), GLSL_VERSION));
            id = shader.id;
            locs = shader.locs;
        }
        Shader(const std::string& vsFileName, const std::string& fsFileName) {
            ::Shader shader = ::LoadShader(TextFormat(vsFileName.c_str(), GLSL_VERSION), TextFormat(fsFileName.c_str(), GLSL_VERSION));
            id = shader.id;
            locs = shader.locs;
            locs[SHADER_LOC_VECTOR_VIEW] = getLocation("viewPos");
        }
        void initLights() {
            lights.push_back(CreateLight(LIGHT_POINT, { 0, 5, 0 },  {0.0f, 0.0f, 0.0f}, YELLOW, *this));
            lights.push_back(CreateLight(LIGHT_POINT, { 0, 5, 0 },  {0.0f, 0.0f, 0.0f}, BLUE, *this));
            lights.push_back(CreateLight(LIGHT_POINT, { 0, 5, 0 },  {0.0f, 0.0f, 0.0f}, RED, *this));
            lights.push_back(CreateLight(LIGHT_POINT, { 0, 5, 0 },  {0.0f, 0.0f, 0.0f}, BLACK, *this));
        }
        void updateLights() {
            UpdateLightValues(*this, lights[0]);
            UpdateLightValues(*this, lights[1]);
            UpdateLightValues(*this, lights[2]);
            UpdateLightValues(*this, lights[3]);
        }
        void unload() {
            ::UnloadShader(*this);
        }
        inline void beginMode() {
            ::BeginShaderMode(*this);
        }
        inline void endMode() {
            ::EndShaderMode();
        }
        inline int getLocation(const std::string& uniformName) const {
            return ::GetShaderLocation(*this, uniformName.c_str());
        }
        inline Shader& setValue(int uniformLoc, const void* value, int uniformType) {
            ::SetShaderValue(*this, uniformLoc, value, uniformType);
            return *this;
        }
        inline Shader& setValue(int uniformLoc, const ::Matrix& mat) {
            ::SetShaderValueMatrix(*this, uniformLoc, mat);
            return *this;
        }
        inline Shader& setValue(int uniformLoc, const ::Texture2D& tex) {
            ::SetShaderValueTexture(*this, uniformLoc, tex);
            return *this;
        }
        std::vector<Light> lights;
    };
}

#endif
