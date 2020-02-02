#include <QLabel>
#include <QDebug>
#include "../headers/game-engine.h"
#include "../headers/tile.h"
#include "../headers/validation.h"
#include "../headers/piece-color.h"
#include "../headers/tile-color.h"

Tile::Tile(QWidget *pParent, Qt::WindowFlags f) : QLabel(pParent, f){};

Tile::Tile(const QString &text, QWidget *pParent, Qt::WindowFlags f) : QLabel(text, pParent, f){};

void Tile::mousePressEvent(QMouseEvent *event)
{
    gameEngine->selectTile(this);
}

void Tile::setPiece(Piece newPiece, PieceColor newPieceColor)
{
    pieceColor = newPieceColor;
    piece = newPiece;
    displayPiece(newPiece);
}

void Tile::displayPiece(Piece elem)
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
            this->clear();
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
        case none:
            this->clear();
            break;
        }
    }
    else
    {
        this->clear();
    }
}

void Tile::tileDisplay()
{
    if (gameEngine != NULL && gameEngine->selectedTile->row == this->row && gameEngine->selectedTile->col == this->col)
    {
        this->setStyleSheet("QLabel { background-color: green; }");
        return;
    }

    // @todo make sure these are actually white
    if (this->tileColor == TileColor::grey)
    {
        this->setStyleSheet("QLabel { background-color: rgb(120, 120, 90); }:hover { background-color: rgb(170,85,127); }");
    }
    else
    {
        this->setStyleSheet("QLabel { background-color: rgb(211, 211, 158); }:hover { background-color: rgb(170,95,127); }");
    }
}