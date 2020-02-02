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
    int availableMoves[60];
    int max = 0;
    int wR;
    int wC;
    int bR;
    int bC;

    void selectingPiece(Tile *);
    void selectingMove(Tile *);

public:
    Tile *selectedTile;
    GameEngine();
    GameEngine(Board *);
    void selectTile(Tile *);
    void setAvailableMoves();
    int chooser(Tile *);
    int validateBishop(Tile *);
    int validateQueen(Tile *);
    int validateKnight(Tile *);
    int validateKing(Tile *);
    int validateRook(Tile *);
    int validatePawn(Tile *);
    bool isGameOver();
    void doMove(Tile *);
};

extern GameEngine *gameEngine;