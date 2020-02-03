#pragma once

#include <list>
#include "../headers/piece-color.h"
#include "../headers/piece.h"

using namespace std;
class Player
{
public:
    PieceColor pieceColor;
    int points;
    list<Piece> lostPieces;
    list<Piece>::iterator lostPiecesIndex;
    int timeLeft;

    Player(PieceColor color);
    int addPointsToPlayer(Piece);
    void addPieceToLostPieces(Piece);
};