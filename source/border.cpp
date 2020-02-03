#include <QLabel>
#include "../headers/border.h"

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

    outLabel->setStyleSheet("QLabel { background-color: #21100D; color : black; }");
}