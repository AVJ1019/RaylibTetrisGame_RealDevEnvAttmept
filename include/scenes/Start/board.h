#pragma once
#include "Renderer.h"
#include "tetromino.h"

class Board
{
private:
    int row = -1, col = -1, combo = 0;
    float tetrominoFieldSize = -1, startPosX = 0, startPosY = 0;
    std::vector<int> grid;
    int score = 0;

public:
    Board(int rows, int cols);
    ~Board() = default;
    void draw(Renderer *renderer);
    void update();

    const std::vector<int> &getGrid() const { return grid; };
    float getTetrominoSize() const { return tetrominoFieldSize; }
    Vector2 getGridOffset() const { return {startPosX, startPosY}; }

    bool lockInTetromino(const Tetromino *tet);
};