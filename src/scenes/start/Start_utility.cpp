#include "Start_utility.h"
#include <iostream>

void generateTetromino(const Board *board, Tetromino *&tetromino)
{
    auto offsets = board->getGridOffset();
    tetromino = new Tetromino(board->getTetrominoSize(), offsets.x, offsets.y);
}

void holdTetromino(Tetromino *&active, Tetromino *&waiting, const Board *board)
{

    if (waiting == nullptr)
    {
        waiting = active;
        waiting->swapped();
        generateTetromino(board, active);
        return;
    }

    auto *temp = active;
    active = waiting;
    waiting = temp;
    waiting->swapped();
    active->swapped();
    active->resetPosition();
}
