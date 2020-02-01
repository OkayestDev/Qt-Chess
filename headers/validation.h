#pragma once

#include "tile.h"

extern Tile *tile[8][8];
extern int exp[60], max, wR, wC;

class Validation
{
    int flag, retVal;

public:
    Validation();
    int chooser(Tile *temp);
    int validateBishop(Tile *temp);
    int validateQueen(Tile *temp);
    int validateKing(Tile *temp);
    int validateHorse(Tile *temp);
    int validateRook(Tile *temp);
    int validatePawn(Tile *temp);
    void orange();
    int check(Tile *temp);
};
