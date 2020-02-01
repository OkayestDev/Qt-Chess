#include "../headers/tile.h"
#include "../headers/validation.h"
#include "../headers/piece-color.h"
#include "../headers/tile-color.h"

extern int count, turn;
extern QWidget *myWidget;

void Tile::mousePressEvent(QMouseEvent *event)
{
    validate(this, ++count);
}

void Tile::setPiece(Piece newPiece, PieceColor newPieceColor)
{
    pieceColor = newPieceColor;
    piece = newPiece;
    display(newPiece);
}

void Tile::display(Piece elem)
{
    this->piece = elem;

    if (this->pieceColor == PieceColor::white && this->piece)
    {
        switch (elem)
        {
        case pawn:
            this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
            break;
        case rook:
            this->setPixmap(QPixmap(":/Images/rook_white.svg"));
            break;
        case knight:
            this->setPixmap(QPixmap(":/Images/knight_white.svg"));
            break;
        case king:
            this->setPixmap(QPixmap(":/Images/king_white.svg"));
            break;
        case queen:
            this->setPixmap(QPixmap(":/Images/queen_white.svg"));
            break;
        case bishop:
            this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
            break;
        case none:
            break;
        }
    }
    else if (this->piece)
    {
        switch (elem)
        {
        case pawn:
            this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
            break;
        case rook:
            this->setPixmap(QPixmap(":/Images/rook_black.svg"));
            break;
        case knight:
            this->setPixmap(QPixmap(":/Images/knight_black.svg"));
            break;
        case king:
            this->setPixmap(QPixmap(":/Images/king_black.svg"));
            break;
        case queen:
            this->setPixmap(QPixmap(":/Images/queen_black.svg"));
            break;
        case bishop:
            this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
            break;
        }
    }
    else
    {
        this->clear();
    }
}

void Tile::validate(Tile *temp, int c)
{
    //     int retValue, i;

    //     if (c == 1)
    //     {
    //         if (temp->piece && (temp->pieceColor == turn))
    //         {
    //             retValue = valid->chooser(temp);

    //             if (retValue)
    //             {
    //                 clickedTile = new Tile();
    //                 temp->setStyleSheet("QLabel {background-color: green;}");
    //                 clickedTile = temp;
    //             }
    //             else
    //             {
    //                 temp->setStyleSheet("QLabel {background-color: red;}");
    //                 count = 0;
    //             }
    //         }
    //         else
    //         {
    //             count = 0;
    //         }
    //     }

    //     else
    //     {

    //         if (temp->tileNum == clickedTile->tileNum)
    //         {
    //             clickedTile->tileDisplay();
    //             disOrange();
    //             max = 0;
    //             count = 0;
    //         }

    //         for (i = 0; i < max; i++)
    //         {
    //             if (temp->tileNum == exp[i])
    //             {
    //                 clickedTile->piece = 0;
    //                 temp->piece = 1;

    //                 temp->pieceColor = clickedTile->pieceColor;
    //                 temp->piece = clickedTile->piece;

    //                 clickedTile->display(clickedTile->piece);
    //                 temp->display(clickedTile->piece);

    //                 clickedTile->tileDisplay();
    //                 temp->tileDisplay();

    //                 retValue = valid->check(clickedTile);

    //                 disOrange();

    //                 max = 0;

    //                 turn = (turn + 1) % 2;
    //                 count = 0;
    //             }

    //             else
    //                 count = 1;
    //         }
    //     }
}

void Tile::tileDisplay()
{
    // @todo make sure these are actually white
    if (this->tileColor == TileColor::grey)
    {
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    }
    else
    {
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
    }
}

// void disOrange()
// {
//     int i;

//     for (i = 0; i < max; i++)
//     {
//         tile[exp[i] / 8][exp[i] % 8]->tileDisplay();
//     }
// }
