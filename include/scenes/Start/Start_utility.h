#pragma once
#include "tetromino.h"
#include "board.h"

void holdTetromino(Tetromino*&, Tetromino*&,const Board*);
void generateTetromino(const Board*, Tetromino*&);