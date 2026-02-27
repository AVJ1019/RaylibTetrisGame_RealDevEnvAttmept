#include "Start.h"
#include <iostream>

Start::Start(AssetMananger *am, int rows, int cols) : Scene(am), row(rows), col(cols)
{
    playArea = new Board(row, col);
    playArea->update();
    // Sådan skal nye brikker indsættes
    auto offsets = playArea->getGridOffset();
    activePiece = new Tetromino(playArea->getTetrominoSize(), offsets.x, offsets.y);
    ents->addEntity(activePiece);
}

void Start::draw(Renderer *renderer)
{
    playArea->draw(renderer);
    ents->draw(renderer);
}

void Start::update(float dt)
{
    static float tPass = 0;
    if (IsKeyPressed(KEY_LEFT) && activePiece->canMove(playArea->getGrid(), -1, 0, 0, col))
        std::cout << "[START] Tetromino moved LEFT...\n";
    if (IsKeyPressed(KEY_RIGHT) && activePiece->canMove(playArea->getGrid(), 1, 0, 0, col))
        std::cout << "[START] Tetromino moved RIGHT...\n";
    if (IsKeyPressed(KEY_SPACE))
        while (activePiece->canMove(playArea->getGrid(), 0, 1, 0, col))
        {
        }
    if (IsKeyPressed(KEY_UP) && activePiece->canMove(playArea->getGrid(), 0, 0, 1, col))
        std::cout << "[START] Tetromino ROTATED...\n";
    else if (IsKeyPressed(KEY_UP) && !activePiece->canMove(playArea->getGrid(), 0, 0, 1, col))
    {
        // activePiece->canMove(playArea->getGrid(), 0, -1, 0, col);
        activePiece->canMove(playArea->getGrid(), 0, 0, 1, col);
        std::cout << "[START] Tetromino moved UP and ROTATED...\n";
    }
    if (tPass < (dt * dropRate))
        tPass += dt;
    else
    {
        activePiece->canMove(playArea->getGrid(), 0, 1, 0, col);
        tPass = 0;
    }
    if (!activePiece->isAlive())
    {
        std::cout << "[START] Tetromino LOCKED IN...\n";
        if (!playArea->lockInTetromino(activePiece))
            std::cout << "[START] GAME OVER!\n";
        ents->removeEntity(activePiece);
        auto offsets = playArea->getGridOffset();
        activePiece = new Tetromino(playArea->getTetrominoSize(), offsets.x, offsets.y);
        ents->addEntity(activePiece);
        playArea->update();
    }
    ents->update(dt);
}