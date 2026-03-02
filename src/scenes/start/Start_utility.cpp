#include "Start_utility.h"
#include <iostream>

void generateTetromino(const Board *board, Tetromino *&tetromino)
{
    auto offsets = board->getGridOffset();
    tetromino = new Tetromino(board->getTetrominoSize(), offsets.x, offsets.y);
    std::cout << "I ran\n";
}

void holdTetromino(Tetromino *&active, Tetromino *&waiting, const Board *board)
{
    if (active != nullptr && waiting != nullptr)
    {
        auto *temp = active;
        active = waiting;
        waiting = temp;
        return;
    }
    if (waiting == nullptr)
    {
        waiting = active;
        generateTetromino(board, active);
    }
}
