#include "GameEngine.h"
#include "mainMenu.h"
#include <iostream>

void GameEngine::run()
{
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "My game");
    BeginDrawing();
    SetTargetFPS(60);

    sceneManager = new SceneManager();
    assetManager = new AssetMananger();
    renderer = new Renderer();

    dt = GetFrameTime(); // Henter frametime, så man kan renge hastigheder dynamnisk

    while (!WindowShouldClose())
    {
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

    if (IsKeyPressed(KEY_ENTER))
    {
        std::cout << "[GAME ENGINE] Changing scene...\n";
        sceneManager->changeScene(new mainMenu(assetManager));
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