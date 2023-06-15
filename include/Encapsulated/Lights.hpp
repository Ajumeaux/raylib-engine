/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Lights
*/

#ifndef LIGHTS_HPP_
#define LIGHTS_HPP_

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

#define MAX_LIGHTS 4

typedef struct {
    int type;
    Vector3 position;
    Vector3 target;
    Color color;
    bool enabled;
    
    int enabledLoc;
    int typeLoc;
    int posLoc;
    int targetLoc;
    int colorLoc;
} Light;

typedef enum {
    LIGHT_DIRECTIONAL,
    LIGHT_POINT
} LightType;


void UpdateLightValues(::Shader shader, Light light);
Light CreateLight(int type, Vector3 position, Vector3 target, Color color, ::Shader shader);

#endif