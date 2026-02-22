#include "GameEngine.h"
#include "mainMenu.h"
#include <iostream>

void GameEngine::run()
{
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "My game");
    BeginDrawing();
    SetTargetFPS(60);

    assetManager = new AssetMananger();
    sceneManager = new SceneManager(assetManager);
    renderer = new Renderer();

    
    while (!WindowShouldClose())
    {
        dt = GetFrameTime(); // Henter frametime, så man kan renge hastigheder dynamnisk
        handleInput(); // Skal spillet pause?
        update(dt); // Updater alle entities
        draw(); // Lad alle opdaterede entities opdatere
    }

    CloseWindow();
}

void GameEngine::handleInput()
{
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (sceneManager->togglePause())
        {
            std::cout << "[GAME ENGINE] Scene is paused...\n";
        }
        else
        {
            std::cout << "[GAME ENGINE] Scene is resumed!\n";
        }
    } 
}

void GameEngine::update(float dt)
{
    sceneManager->update(dt);
}

void GameEngine::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    sceneManager->draw(renderer);

    EndDrawing();
}