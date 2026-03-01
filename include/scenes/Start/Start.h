#pragma once
#include "SceneManager.h"
#include "board.h"
#include "tetromino.h"

class Start : public Scene
{
private:
    Board *playArea = nullptr;
    Tetromino *activePiece = nullptr;
    int score;
    float dropRate = 15, intervalChange = 0.95; // dropRate er lig med 1 sekund således 

public:
    Start(AssetMananger *am);
    ~Start();
    void update(float dt) override;
    void draw(Renderer *renderer) override;
    int getGameResults() override;
};

inline Start::~Start()
{
    delete playArea;
}