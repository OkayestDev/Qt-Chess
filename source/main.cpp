#include <QApplication>
#include "mainwindow.h"
#include "tile.h"

int count = 0, turn = 1, exp[60], max = 0;
int wR, wC, bR, bC;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(0, 0, 1370, 700);

    accessories(myWidget);
    chessBoard(myWidget, tile);

    myWidget->show();
    return app.exec();
}
