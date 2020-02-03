#pragma once

#include "../headers/piece-color.h"
#include "../headers/piece.h"

class Player
{
public:
    PieceColor pieceColor;
    int points;
    Piece lostPieces[16];
    int timeLeft;

    Player(PieceColor color);
};