#pragma once
#include "AssetManager.h"

class Renderer
{
public:
    Renderer() = default;
    ~Renderer();
    void DrawSprite();
    void drawRectangle(Rectangle&, Color);
};

inline Renderer::~Renderer()
{
}