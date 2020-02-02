#pragma once

#include <QWidget>
#include "./tile.h"
#include "./border.h"

class Board
{
private:
    Tile *tiles[8][8] = {{NULL}};
    Border *border[4] = {NULL};

public:
    Board();
    Board(QWidget *);
    void accessories(QWidget *);
    void placePawns();
    void placePowerPieces();
    void generateEmptyBoard(QWidget *);
    void deselectAllTilesExcept(Tile *);
};
