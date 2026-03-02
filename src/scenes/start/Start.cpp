#include "Start.h"
#include "States.h"
#include "Start_utility.h"
#include <iostream>

Start::Start(AssetMananger *am) : Scene(am)
{
    playArea = new Board(ROWS, COLS);
    playArea->update();
    // Sådan skal nye brikker indsættes
    generateTetromino(playArea, activePiece);
    ents->addEntity(activePiece);
}

void Start::draw(Renderer *renderer)
{
    playArea->draw(renderer);
    ents->draw(renderer);
    renderer->drawText(std::to_string(playArea->getScore()), 100, 0, 0.1, RED);
}

void Start::update(float dt)
{
    static float tPass = 0;
    if (IsKeyPressed(KEY_LEFT))
        activePiece->canMove(playArea->getGrid(), -1, 0, 0);

    if (IsKeyPressed(KEY_RIGHT))
        activePiece->canMove(playArea->getGrid(), 1, 0, 0);

    if (IsKeyPressed(KEY_SPACE))
        while (activePiece->canMove(playArea->getGrid(), 0, 1, 0))
        {
        }

    if (IsKeyPressed(KEY_UP))
        activePiece->canMove(playArea->getGrid(), 0, 0, 1);
    if(IsKeyPressed(KEY_C) && !swapUsed)
    {
        holdTetromino(activePiece, waitingPiece, playArea);
        if(!ents->containsEntity(activePiece))
            ents->addEntity(activePiece);
        swapUsed = true;
    }
    if (tPass < (dt * dropRate))
        tPass += dt;
    else
    {
        activePiece->canMove(playArea->getGrid(), 0, 1, 0);
        tPass = 0;
    }
    if (!activePiece->isAlive())
    {
        if (!playArea->lockInTetromino(activePiece))
        {
            nextScene = STATE_GAME_OVER;
            sceneDone = true;
            score = playArea->getScore();
        }
        ents->removeEntity(activePiece);
        generateTetromino(playArea, activePiece);
        ents->addEntity(activePiece);
        playArea->update();
        swapUsed = false;
    }
    ents->update(dt);
}

int Start::getGameResults()
{
    return score;
}