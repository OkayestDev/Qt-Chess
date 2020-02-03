#pragma once

#include "./piece-color.h"
#include "./tile.h"
#include "./board.h"
#include "./available-moves.h"
#include "./player.h"

class GameEngine
{
private:
    PieceColor turn;
    Board *board;
    AvailableMoves *availableMoves;
    Player *player1;
    Player *player2;
    int moveCount;
    int availableMovesArray[60];
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
    GameEngine(Board *, Player *, Player *);
    void capturePiece(Tile *, Tile *);
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
    void prepareNewMove();
    void doMove(Tile *);
};

extern GameEngine *gameEngine;
