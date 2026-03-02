#pragma once
#include "Renderer.h"
#include "EntityManager.h"
#include "shapeGen.h"

class Tetromino : public entity
{
private:
    int x = -1, y = 0, rot = 0;
    TetrominoData shapeData;
    float tetrominoSize = 1, offsetX = 0, offsetY = 0;
    bool shouldPrint = true;

public:
    Tetromino(float size, int offX, int offY);
    ~Tetromino();
    void update(float dt) override;
    bool canMove(const std::vector<int> &grid, int xMov, int yMov, int rMov);
    void draw(Renderer *renderer) override;
    int getShapeVal(int posX, int posY) const;
    Vector2 getPos() const { return {(float)x, (float)y}; }
    void resetPosition();
    void swapped() { shouldPrint = !shouldPrint; }
};

inline Tetromino::~Tetromino() {}