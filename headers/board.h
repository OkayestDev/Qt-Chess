#pragma once

#include <QWidget>
#include "./tile.h"
#include "./border.h"

class Board
{
private:
    Border *border[4] = {NULL};

public:
    Tile *tiles[8][8] = {{NULL}};
    Board();
    Board(QWidget *);
    Tile *getTile(int row, int col);
    void accessories(QWidget *);
    void placePawns();
    void placePowerPieces();
    void generateEmptyBoard(QWidget *);
    void displayTiles();
};
