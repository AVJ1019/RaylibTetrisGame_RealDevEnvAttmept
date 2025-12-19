#pragma once
#include <unordered_map>
#include <string>
#include "raylib.h"

class AssetMananger
{
private:
    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, Sound> sounds;

public:
    void loadTexture(std::string path, std::string key);
    void loadSound(std::string path, std::string key);

    Texture2D getTexture(std::string key);
    Sound getSound(std::string key);

    AssetMananger()  = default;
    ~AssetMananger();
};

inline AssetMananger::~AssetMananger()
{
    for(auto& pair : textures) UnloadTexture(pair.second);
    for(auto& pair : sounds) UnloadSound(pair.second);
}