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
    bool isSelected;
    int row;
    int col;
    int tileNum;

    Tile(QWidget *pParent = 0, Qt::WindowFlags f = 0);
    Tile(const QString &text, QWidget *pParent = 0, Qt::WindowFlags f = 0);

    void mousePressEvent(QMouseEvent *);
    void displayPiece(Piece);
    void tileDisplay();
    void setPiece(Piece, PieceColor);
    void validate(Tile *, int);
};
