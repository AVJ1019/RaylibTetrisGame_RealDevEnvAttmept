#include "tetromino_helpers.h"
#include "config.h"
#include <random>
#include <iostream>

int getRandomShape()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<int> dist(0, 6);
    return dist(mt);
}

void loopTetromino(int tet[16], std::function<void(int x, int y, int val)> f)
{
    for (auto i{0}; i < 4; i++)
    {
        for (auto j{0}; j < 4; j++)
        {
            f(j, i, tet[i * 4 + j]);
        }
    }
}

bool canMoveX(const std::vector<int> &grid, int xDir, int CurX, int CurY, int shape[16])
{
    int targetX;
    int targetY;
    for (auto xOff{0}; xOff < TETROMINO_GRID_SIZE; xOff++)
    {
        targetX = CurX + xOff + xDir;
        if (shape[targetX] != 0)
            if (targetX < 0 || targetX > COLS)
                return false;
        for (auto yOff{0}; yOff < TETROMINO_GRID_SIZE; yOff++)
        {
            targetY = (yOff + CurY) * TETROMINO_GRID_SIZE + targetX;
            if (shape[targetY] != 0)
                if (targetY >= grid.size() || grid.at(targetY) != 0)
                    return false;
        }
    }
    return true;
}

bool canMoveX()
{
    return false;
}

bool canMoveRot()
{
    return false;
}