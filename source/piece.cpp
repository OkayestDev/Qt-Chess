#include <map>
#include "../headers/piece.h"

std::map<Piece, int> pieceToPoints = {
    {none, 0},
    {pawn, 1},
    {rook, 5},
    {knight, 3},
    {bishop, 3},
    {queen, 9},
    {king, 0}};
