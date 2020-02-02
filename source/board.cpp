#include "../headers/board.h"
#include "../headers/border.h"
#include "../headers/tile.h"
#include "../headers/piece.h"
#include "../headers/piece-color.h"
#include "../headers/tile-color.h"

Board::Board(QWidget *baseWidget)
{
    border[0]->outline(baseWidget, 330, 105, 0);
    border[1]->outline(baseWidget, 330, 637, 0);
    border[2]->outline(baseWidget, 330, 125, 1);
    border[3]->outline(baseWidget, 862, 125, 1);

    generateEmptyBoard(baseWidget);
    placePawns();
    placePowerPieces();
    accessories(baseWidget);
}

void Board::accessories(QWidget *baseWidget)
{
    QLabel *player2 = new QLabel(baseWidget);
    QLabel *name2 = new QLabel("Player 2", baseWidget);
    QLabel *time2 = new QLabel("00:00:00", baseWidget);

    QLabel *player1 = new QLabel(baseWidget);
    QLabel *name1 = new QLabel("Player 1", baseWidget);
    QLabel *time1 = new QLabel("00:00:00", baseWidget);

    QLabel *moves = new QLabel(baseWidget);

    name1->setGeometry(125, 610, 80, 20);
    time1->setGeometry(120, 635, 80, 20);
    player1->setGeometry(100, 500, 100, 100);
    player1->setPixmap(QPixmap(":/Images/profile.png"));

    name2->setGeometry(125, 210, 80, 20);
    time2->setGeometry(120, 235, 80, 20);
    player2->setGeometry(100, 100, 100, 100);
    player2->setPixmap(QPixmap(":/Images/profile.png"));

    moves->setGeometry(1000, 105, 250, 550);
    moves->setStyleSheet("QLabel {background-color: white;}");
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
                                         ? TileColor::grey
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
        tiles[1][j]->setPiece(pawn, PieceColor::black);
        tiles[6][j]->setPiece(pawn, PieceColor::white);
    }
}

void Board::placePowerPieces()
{
    // Black
    tiles[0][0]->setPiece(rook, PieceColor::black);
    tiles[0][1]->setPiece(knight, PieceColor::black);
    tiles[0][2]->setPiece(bishop, PieceColor::black);
    tiles[0][3]->setPiece(queen, PieceColor::black);
    tiles[0][4]->setPiece(king, PieceColor::black);
    tiles[0][5]->setPiece(bishop, PieceColor::black);
    tiles[0][6]->setPiece(knight, PieceColor::black);
    tiles[0][7]->setPiece(rook, PieceColor::black);
    // White
    tiles[7][0]->setPiece(rook, PieceColor::white);
    tiles[7][1]->setPiece(knight, PieceColor::white);
    tiles[7][2]->setPiece(bishop, PieceColor::white);
    tiles[7][3]->setPiece(queen, PieceColor::white);
    tiles[7][4]->setPiece(king, PieceColor::white);
    tiles[7][5]->setPiece(bishop, PieceColor::white);
    tiles[7][6]->setPiece(knight, PieceColor::white);
    tiles[7][7]->setPiece(rook, PieceColor::white);
}

void Board::displayTiles()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tiles[i][j]->tileDisplay();
        }
    }
}
