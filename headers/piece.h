#pragma once

#include <map>

enum Piece
{
    none = 0,
    pawn = 1,
    rook = 2,
    knight = 3,
    bishop = 4,
    queen = 5,
    king = 6,
};
const std::map<Piece, int> pieceToPoints;
