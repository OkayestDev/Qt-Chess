#include <QApplication>
#include "../headers/game-engine.h"
#include "../headers/tile.h"
#include "../headers/board.h"
#include "../headers/player.h"

GameEngine *gameEngine = NULL;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(0, 0, 1370, 700);

    Player *player1 = new Player(white);
    Player *player2 = new Player(black);

    Board *board = new Board(myWidget);
    gameEngine = new GameEngine(board);

    myWidget->show();
    return app.exec();
}
