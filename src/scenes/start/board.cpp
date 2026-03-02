#include "board.h"
#include <functional>
#include <iostream>
#include "colorFactory.h"

// helpers
void loopGrid(std::vector<int> &grid, int col, int row, std::function<void(int x, int y, int val)> f);
void printGrid(std::vector<int> &grid, int col, int row);

Board::Board(int rows, int cols) : row(rows), col(cols)
{
    grid.resize(row * col, 0);
    float padding = BOARD_PADDING;
    float defaultSize = 50;

    float widthScale = (GetScreenWidth() - padding) / (defaultSize * col);
    float heightScale = (GetScreenHeight() - padding) / (defaultSize * row);

    float finalScale = (widthScale < heightScale) ? widthScale : heightScale;

    startPosX = (GetScreenWidth() / 2) - (col * tetrominoFieldSize / 2);
    startPosY = BOARD_PADDING / 2;

    tetrominoFieldSize = defaultSize * finalScale;
}

void Board::draw(Renderer *renderer)
{

    loopGrid(grid, col, row, [&](int x, int y, int val)
             { if(val == 0)
                renderer->drawSqr((x * tetrominoFieldSize) + startPosX, (y * tetrominoFieldSize) + startPosY, tetrominoFieldSize, RED, false);
                else
                renderer->drawSqr((x * tetrominoFieldSize) + startPosX, (y * tetrominoFieldSize) + startPosY, tetrominoFieldSize, colorFactory(val), true); });
}

void Board::update()
{
    int linesCleared = 0;
    for (auto y{row - 1}; y > 0; y--)
    {
        bool fullLine = true;
        for (auto x{0}; x < col; x++)
        {
            if (grid.at((y * col) + x - 1) == 0)
            {
                fullLine = false;
                continue;
            }
        }
        if (fullLine)
        {
            auto start = grid.begin() + (y * col);
            auto end = grid.begin() + (y * col) + col;

            grid.erase(start, end);

            grid.insert(grid.begin(), col, 0);

            y++;

            linesCleared++;
        }
    }
    if (linesCleared > 0)
    {
        score += (10 * linesCleared) + (combo * 10);
        combo += linesCleared;
    }
    else
        combo = 0;
}

void loopGrid(std::vector<int> &grid, int col, int row, std::function<void(int x, int y, int val)> f)
{
    for (auto i{0}; i < row; i++)
    {
        for (auto j{0}; j < col; j++)
        {
            f(j, i, grid.at(i * col + j));
        }
    }
}

void printGrid(std::vector<int> &grid, int col, int row)
{
    for (auto i{0}; i < row; i++)
    {
        for (auto j{0}; j < col; j++)
        {
            std::cout << grid.at(i * col + j) << " ";
        }
        std::cout << "\n";
    }
}

bool Board::lockInTetromino(const Tetromino *tet)
{
    auto tetPos = tet->getPos();
    for (auto i{0}; i < 4; i++)
    {
        for (auto j{0}; j < 4; j++)
        {
            if ((tetPos.y + j) * col < 20)
                return false;
            if (tet->getShapeVal(i, j) != 0)
                grid[(tetPos.y + j) * col + tetPos.x + i] = tet->getShapeVal(i, j);
        }
    }
    return true;
}
