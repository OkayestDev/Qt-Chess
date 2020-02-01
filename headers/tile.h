#pragma once

#include <QLabel>
#include <QDebug>
#include "./piece.h"
#include "./tile-color.h"
#include "./piece-color.h"

class Tile : public QLabel
{
public:
    TileColor tileColor;
    Piece piece;
    PieceColor pieceColor;
    int row;
    int col;
    int tileNum;

    Tile(QWidget *pParent = 0, Qt::WindowFlags f = 0) : QLabel(pParent, f){};
    Tile(const QString &text, QWidget *pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};

    void mousePressEvent(QMouseEvent *);
    void display(Piece);
    void tileDisplay();
    void setPiece(Piece, PieceColor);
    void validate(Tile *, int);
};
