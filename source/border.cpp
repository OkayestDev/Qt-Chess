#include <QLabel>
#include "border.h"

Border::Border() {}

void Border::outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
{
    QLabel *outLabel = new QLabel(baseWidget);

    if (!Pos)
    {
        outLabel->setGeometry(xPos, yPos, 552, 20); // Horizontal Borders
    }
    else
    {
        outLabel->setGeometry(xPos, yPos, 20, 512); // Vertical Borders
    }

    outLabel->setStyleSheet("QLabel { background-color :rgb(170, 170, 127); color : black; }");
}

void Border::accessories(QWidget *baseWidget)
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