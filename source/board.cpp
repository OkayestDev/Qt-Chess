#include "./board.h"
#include "./border.h"
#include "./tile.h"
#include "./piece.h"
#include "./piece-color.h"
#include "./tile-color.h"

Board::Board(QWidget *baseWidget)
{
    int i, j, k = 0, hor, ver;

    border[0]->outline(baseWidget, 330, 105, 0);
    border[1]->outline(baseWidget, 330, 637, 0);
    border[2]->outline(baseWidget, 330, 125, 1);
    border[2]->outline(baseWidget, 862, 125, 1);

    generateEmptyBoard(baseWidget);
    placePawns();
    placePowerPieces();
}

void Board::generateEmptyBoard(QWidget *baseWidget)
{
    // Create 64 tiles (allocating memories to the objects of Tile class)
    int ver = 125;
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        int hor = 350;
        for (int j = 0; j < 8; j++)
        {
            tiles[i][j] = new Tile(baseWidget);
            tiles[i][j]->tileColor = (i + j) % 2 == 0
                                         ? TileColor::white
                                         : TileColor::brown;
            tiles[i][j]->piece = none;
            tiles[i][j]->row = i;
            tiles[i][j]->col = j;
            tiles[i][j]->tileNum = k++;
            tiles[i][j]->tileDisplay();
            tiles[i][j]->setGeometry(hor, ver, 64, 64);
            hor += 64;
        }
        ver += 64;
    }

    // @todo da fuq?
    int wR = 7;
    int wC = 4;

    int bR = 0;
    int bC = 4;
}

void Board::placePawns()
{
    for (int j = 0; j < 8; j++)
    {
        tiles[1][j]->setPiece(pawn, white);
        tiles[1][j]->setPiece(pawn, black);
    }
}

void Board::placePowerPieces()
{
    // White
    tiles[0][0]->setPiece(rook, white);
    tiles[0][1]->setPiece(knight, white);
    tiles[0][2]->setPiece(bishop, white);
    tiles[0][3]->setPiece(queen, white);
    tiles[0][4]->setPiece(king, white);
    tiles[0][5]->setPiece(bishop, white);
    tiles[0][6]->setPiece(knight, white);
    tiles[0][7]->setPiece(rook, white);
    // Black
    tiles[7][0]->setPiece(rook, black);
    tiles[7][1]->setPiece(knight, black);
    tiles[7][2]->setPiece(bishop, black);
    tiles[7][3]->setPiece(queen, black);
    tiles[7][4]->setPiece(king, black);
    tiles[7][5]->setPiece(bishop, black);
    tiles[7][6]->setPiece(knight, black);
    tiles[7][7]->setPiece(rook, black);
}
