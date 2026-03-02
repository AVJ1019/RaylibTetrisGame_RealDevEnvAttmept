#include "tetromino.h"
#include "tetromino_helpers.h"
#include "config.h"
#include "colorFactory.h"
#include <functional>
#include <random>
#include <iostream>

Tetromino::Tetromino(float size, int offX, int offY) : tetrominoSize(size), offsetX(offX), offsetY(offY)
{
    rot = 0;
    x = COLS / 2;
    shapeData = shapeGen(static_cast<SHAPES>(getRandomShape()));
}

bool Tetromino::canMove(const std::vector<int> &grid, int xMov, int yMov, int rMov)
{
    int targetX = x;
    int targetY = y;
    int targetRot = (rot + rMov) % 4;

    if (canMoveX(grid, xMov, x, y, shapeData.rotData[targetRot]))
        x += xMov;
    else
        return false;
    if (!canMoveY(grid, yMov, x, y, shapeData.rotData[targetRot]))
    {
        alive = false;
        return false;
    }

    rot = targetRot;
    y += yMov;
    return true;
}

void Tetromino::update(float dt)
{
}

void Tetromino::draw(Renderer *renderer)
{
    if (shouldPrint)
        loopTetromino(shapeData.rotData[rot], [&](int shapeX, int shapeY, int val)
                      {
                      if (val != 0)
                          renderer->drawSqr(((x + shapeX) * tetrominoSize) + offsetX, ((y + shapeY) * tetrominoSize) + offsetY, tetrominoSize, colorFactory(val), true); });
}

int Tetromino::getShapeVal(int posX, int posY) const
{
    return shapeData.rotData[rot][(posY * 4) + posX];
}

void Tetromino::resetPosition()
{
    x = COLS / 2;
    y = 0;
    rot = 0;
}
