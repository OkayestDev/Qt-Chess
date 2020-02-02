#include "../headers/game-engine.h"
#include "../headers/board.h"
#include "../headers/tile.h"
#include "../headers/piece-color.h";

GameEngine::GameEngine(){};

GameEngine::GameEngine(Board *_board)
{
    this->board = _board;
    this->moveCount = 0;
    this->turn = PieceColor::white;
}

void GameEngine::selectTile(Tile *tile)
{
    // Only allow selecting of player's pieces
    if (tile->pieceColor == this->turn)
    {
        tile->isSelected = true;
        this->board->deselectAllTilesExcept(tile);
    }
}

bool GameEngine::isGameOver()
{
}
