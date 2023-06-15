/*
** EPITECH PROJECT, 2023
** game
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_


#include "./BaseRaylib.hpp"
#include "Shader.hpp"

using namespace OriginalRaylib;

namespace Raylib {
    class Model : public ::Model {
    public:
        Model(const std::string& modelPath, const std::string& texturePath) {
            ::Model model = ::LoadModel(modelPath.c_str());

            transform = model.transform;
            meshCount = model.meshCount;
            materialCount = model.materialCount;
            meshes = model.meshes;
            materials = model.materials;
            meshMaterial = model.meshMaterial;
            boneCount = model.boneCount;
            bones = model.bones;
            bindPose = model.bindPose;

            ::Texture texture = ::LoadTexture(texturePath.c_str());
            ::SetTextureFilter(texture, TEXTURE_FILTER_ANISOTROPIC_16X);
            ::SetMaterialTexture(&materials[0], MATERIAL_MAP_DIFFUSE, texture);
            _textures.push_back(texture);
            _textureCount = 1;
            totalAnims = -1;
            animFrameCounter = 0;
        }
        Model(const ::Mesh& mesh, const std::string& texturePath) {
            ::Model model = ::LoadModelFromMesh(mesh);
            transform = model.transform;

            meshCount = model.meshCount;
            materialCount = model.materialCount;
            meshes = model.meshes;
            materials = model.materials;
            meshMaterial = model.meshMaterial;

            boneCount = model.boneCount;
            bones = model.bones;
            bindPose = model.bindPose;
            ::Texture texture = ::LoadTexture(texturePath.c_str());
            ::SetTextureFilter(texture, TEXTURE_FILTER_ANISOTROPIC_16X);
            ::SetMaterialTexture(&materials[0], MATERIAL_MAP_DIFFUSE, texture);
            _textures.push_back(texture);
            _textureCount = 1;
            totalAnims = -1;
            animFrameCounter = 0;
        }
        void setTransform(::Matrix matrix) {
            transform = matrix;
        }
        void setShader(Shader shader) {
            materials[0].shader = shader;
        }
        void loadAnimations(const std::string& animPath, unsigned int animsCount) {
            totalAnims = animsCount;
            animations = ::LoadModelAnimations(animPath.c_str(), &animsCount);
        }
        void playAnimation(int index) {
            animFrameCounter++;
            UpdateModelAnimation(*this, animations[index], animFrameCounter);
            if (animFrameCounter >= animations[index].frameCount)
                animFrameCounter = 0;
        }
        void loadTexture(const std::string& texturePath) {
            ::Texture texture = ::LoadTexture(texturePath.c_str());
            ::SetTextureFilter(texture, TEXTURE_FILTER_ANISOTROPIC_16X);
            // ::SetMaterialTexture(&materials[0], MATERIAL_MAP_DIFFUSE, texture);
            _textures.push_back(texture);
            _textureCount++;
        }
        void setTexture(int textureIndex) {
            SetMaterialTexture(&materials[0], MATERIAL_MAP_DIFFUSE, _textures[textureIndex]);
        }
        int getTextureNb() {
            return _textureCount;
        }
        inline void unload() {
            for (auto &i : _textures)
                UnloadTexture(i);
            if (totalAnims >= 0) {
                for (int i = 0; i <= totalAnims; ++i)
                    UnloadModelAnimation(animations[i]);
                RL_FREE(animations);
            }
            ::UnloadModel(*this);
        }
        inline void updateAnimation(const ::ModelAnimation& anim, int frame) {
            ::UpdateModelAnimation(*this, anim, frame);
        }
        inline void draw(::Vector3 position, float scale, ::Color tint) {
            ::DrawModel(*this, position, scale, tint);
        }
        inline void drawEx(::Vector3 position, ::Vector3 scale, ::Color tint) {
            ::DrawModelEx(*this, position, {1.0f, 1.0f, 1.0f}, 0, scale, tint);
        }
        BoundingBox getBoundingBox() {
            return ::GetModelBoundingBox(*this);
        }
        int totalAnims;
        int animFrameCounter;
        ::ModelAnimation *animations;
    private:
        std::vector<::Texture> _textures;
        int _textureCount;
    };
}

#endif