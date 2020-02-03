#include <algorithm>

#include <list>
#include "../headers/player.h"
#include "../headers/piece.h"

Player::Player(PieceColor color)
{
    pieceColor = color;
    points = 0;
    lostPiecesIndex = lostPieces.begin();
    timeLeft = 15;
}

int Player::addPointsToPlayer(Piece capturedPiece)
{
    int pointsToAdd = pieceToPoints.at(capturedPiece);
    points += pointsToAdd;
    return pointsToAdd;
}

void Player::addPieceToLostPieces(Piece capturedPiece)
{
    lostPieces.insert(lostPiecesIndex, capturedPiece);
    lostPiecesIndex++;
}