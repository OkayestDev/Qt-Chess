#pragma once

#include "./tile.h"
#include "./board.h"

class AvailableMoves
{
public:
    AvailableMoves();
    /**
     *  @todo en passant movement
     */
    int availableMovePawn(Tile *tile, int availableMoves[], int &max, Board *board);
    int availableMoveRook(Tile *tile, int availableMoves[], int &max, Board *board);
    int availableMoveKnight(Tile *tile, int availableMoves[], int &max, Board *board);
    int availableMoveKing(Tile *tile, int availableMoves[], int &max, Board *board);
    int availableMoveQueen(Tile *tile, int availableMoves[], int &max, Board *board);
    int availableMoveBishop(Tile *tile, int availableMoves[], int &max, Board *board);
};
