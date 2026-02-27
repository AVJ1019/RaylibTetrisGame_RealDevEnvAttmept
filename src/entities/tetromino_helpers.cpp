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

bool canMoveX(const std::vector<int> &grid, int xDir, int &CurX, int CurY, int shape[16])
{
    int targetX;
    for (auto xOff{0}; xOff < 4; xOff++)
    {
        for (auto yOff{0}; yOff < 4; yOff++)
        {
            if (shape[xOff + (yOff * TETROMINO_GRID_SIZE_SQR)] != 0)
            {
                targetX = CurX + xOff + xDir;
                std::cout << "X: " << CurX << " Y: " << CurY << " TargetX: " << targetX << std::endl;
                if (targetX < 0 || targetX >= COLS)
                {
                    if (targetX < 0)
                        CurX = 0 - xOff;
                    else if (targetX >= COLS)
                        CurX = COLS - 1 - xOff;
                    return false;
                }
                targetX += (yOff + CurY) * COLS;
                if (grid[targetX] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool canMoveY(const std::vector<int> &grid, int yDir, int CurX, int CurY, int shape[16])
{
    int targetY;
    for (auto xOff{0}; xOff < 4; xOff++)
    {
        for (auto yOff{0}; yOff < 4; yOff++)
        {
            if (shape[xOff + (yOff * TETROMINO_GRID_SIZE_SQR)] != 0)
            {
                targetY = CurY + yOff + yDir;
                if (targetY < 0 || targetY >= ROWS)
                    return false;
                targetY *= COLS;
                targetY += CurX + xOff;
                if (grid[targetY] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool canMoveRot(const std::vector<int> &grid, int yDir, int CurX, int CurY, int shape[16])
{
    return false;
}