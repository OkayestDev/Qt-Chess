#pragma once

#include "./piece-color.h"
#include "./tile.h"
#include "./board.h"

class GameEngine
{
private:
    PieceColor turn;
    Board *board;
    int moveCount;
    int exp[60];
    int max = 0;
    int wR;
    int wC;
    int bR;
    int bC;

public:
    GameEngine();
    GameEngine(Board *);
    void selectTile(Tile *);
    bool isGameOver();
};

extern GameEngine *gameEngine;