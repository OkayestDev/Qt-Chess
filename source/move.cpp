#include "../headers/move.h"
#include "../headers/piece.h"

Move::Move(Tile *fromTile, Tile *toTile)
{
    fromRow = fromTile->row;
    fromColumn = fromTile->col;
    fromTileNum = fromTile->tileNum;
    toRow = fromTile->row;
    toColumn = fromTile->col;
    toTileNum = fromTile->tileNum;
    piece = fromTile->piece;
    pieceColor = fromTile->pieceColor;
    isCapture = fromTile->piece != none && fromTile->pieceColor != toTile->pieceColor && toTile->piece != none;
}

QString Move::getMoveAsString()
{
    QString qString = "";

    return qString;
}