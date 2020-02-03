#pragma once

#include "./tile.h"
#include "./piece.h"
#include "./piece-color.h"

class Move
{
private:
    Piece piece;
    PieceColor pieceColor;
    int fromRow;
    int fromColumn;
    int fromTileNum;
    int toRow;
    int toColumn;
    int toTileNum;
    bool isCapture;

public:
    Move(Tile *, Tile *);
    QString getMoveAsString();
};