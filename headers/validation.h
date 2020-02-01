#pragma once

#include "./tile.h"

class Validation
{
private:
    int flag;
    int retVal;

public:
    Validation();
    int chooser(Tile *);
    int validateBishop(Tile *);
    int validateQueen(Tile *);
    int validateKnight(Tile *);
    int validateKing(Tile *);
    int validateRook(Tile *);
    int validatePawn(Tile *);
    void orange();
    int check(Tile *);
};
