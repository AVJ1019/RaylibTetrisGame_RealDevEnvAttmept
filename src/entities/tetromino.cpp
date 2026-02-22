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

bool Tetromino::canMove(const std::vector<int> &grid, int xMov, int yMov, int rMov, int col)
{
    int targetX = x;
    int targetY = y;
    int targetRot = (rot + rMov) % 4;
    for (auto i{0}; i < 4; i++)
    {
        for (auto j{0}; j < 4; j++)
        {
            if (shapeData.rotData[targetRot][j * 4 + i] != 0)
            {
                targetX = x + i + xMov;
                if (!canMoveX(grid, xMov, x, y, shapeData.rotData[targetRot]))
                    return false;
            }
        }
    }
    x += xMov;
    y += yMov;
    rot = targetRot;
    return true;
}

void Tetromino::update(float dt)
{
}

void Tetromino::draw(Renderer *renderer)
{
    loopTetromino(shapeData.rotData[rot], [&](int shapeX, int shapeY, int val)
                  {
                      if (val != 0)
                          renderer->drawSqr(((x + shapeX) * tetrominoSize) + offsetX, ((y + shapeY) * tetrominoSize) + offsetY, tetrominoSize, colorFactory(val), true); });
}

int Tetromino::getShapeVal(int posX, int posY) const
{
    return shapeData.rotData[rot][(posY * 4) + posX];
}