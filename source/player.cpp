#include <algorithm>

#include "../headers/player.h"

Player::Player(PieceColor color)
{
    pieceColor = color;
    points = 0;
    std::fill_n(lostPieces, 16, none);
    timeLeft = 15;
}