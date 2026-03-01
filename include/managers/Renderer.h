#pragma once
#include "AssetManager.h"
#include "config.h"
#include <vector>

class Renderer
{
public:
    Renderer() = default;
    ~Renderer();
    void DrawSprite();
    void drawButton(Rectangle &, Color, std::string);
    void drawText(std::string str, int x, int y, float scale, Color c);
    void drawSqr(int x, int y, int size, Color c, bool filled);
};

inline Renderer::~Renderer()
{
}