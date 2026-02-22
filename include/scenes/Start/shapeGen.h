#pragma once
#include "raylib.h"

enum SHAPES
{
    TETROMINO_STRAIGT,
    TETROMINO_SQUARE,
    TETROMINO_T,
    TETROMINO_L_RIGHT,
    TETROMINO_L_LEFT,
    TETROMINO_SKEW_RIGHT,
    TETROMINO_SKEW_LEFT
};

struct TetrominoData
{
    int rotData[4][16]; // Vi gemmer rotationerne for figur, for at spare CPU tid
    Color color;
};

TetrominoData shapeGen(SHAPES shape);