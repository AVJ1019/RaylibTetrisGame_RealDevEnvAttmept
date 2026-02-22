#include "Renderer.h"

// Helpers
int calcFontSize(std::string s, float btnWitdh, float btnHeight);

void Renderer::DrawSprite()
{
}

void Renderer::drawButton(Rectangle &r, Color c, std::string s)
{
    DrawRectangleRec(r, c);

    auto fs = calcFontSize(s, r.width, r.height);
    auto textSize = MeasureTextEx(GetFontDefault(), s.c_str(), fs, 10); // 10 er halvedel af padding i calcFontSize, som er nødvendig

    float sPosX = r.x + (r.width / 2) - (textSize.x / 2);
    float sPosy = r.y + (r.height / 2) - (textSize.y / 2);

    DrawText(s.c_str(), sPosX, sPosy, fs, RED);
}

void Renderer::drawSqr(int x, int y, int size, Color c, bool filled)
{
    if (!filled)
    {
        DrawRectangleLines(x, y, size, size, c);
        return;
    }
    DrawRectangle(x, y, size, size, c);
}

int calcFontSize(std::string s, float btnWitdh, float btnHeight)
{
    float padding = 20;
    float targetWidth = btnWitdh - padding;
    float targetHeight = btnHeight - padding;

    float defaultSize = 10;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), s.c_str(), defaultSize, 1);

    float widthScale = targetWidth / textSize.x;
    float heightScale = targetHeight / textSize.y;

    float finalScale = (widthScale < heightScale) ? widthScale : heightScale;
    return defaultSize * finalScale;
}