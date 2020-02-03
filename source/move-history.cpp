#include <list>
#include "../headers/move-history.h"
#include "../headers/tile.h"

MoveHistory::MoveHistory()
{
    index = moves.begin();
}

void MoveHistory::addMove(Tile *fromTile, Tile *toTile)
{
    Move newMove = Move(fromTile, toTile);
    moves.insert(index, newMove);
    index++;
}

QString MoveHistory::listToString()
{
    QString qString = "";
    list<Move>::iterator it;
    for (it = moves.begin(); it != moves.end(); it++)
    {
        Move move = *it;
        qString.append(move.getMoveAsString() + " ");
    }

    return qString;
}