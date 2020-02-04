#include <algorithm>

#include "../headers/game-engine.h"
#include "../headers/board.h"
#include "../headers/tile.h"
#include "../headers/piece-color.h"
#include "../headers/piece.h"
#include "../headers/available-moves.h"

using namespace std;

GameEngine::GameEngine(){};

GameEngine::GameEngine(Board *_board, Player *_player1, Player *_player2)
{
    this->board = _board;
    this->availableMoves = new AvailableMoves();
    this->moveCount = 0;
    player1 = _player1;
    player2 = _player2;
    this->turn = PieceColor::white;
}

void GameEngine::selectTile(Tile *tile)
{
    // Only allow selecting of player's pieces
    if (tile->piece != none && tile->pieceColor == this->turn)
    {
        selectingPiece(tile);
    }
    else
    {
        selectingMove(tile);
    }
}

void GameEngine::selectingPiece(Tile *tile)
{
    prepareNewMove();
    selectedTile = tile;

    switch (tile->piece)
    {
    case pawn:
        availableMoves->availableMovePawn(tile, availableMovesArray, max, board);
        break;
    case rook:
        availableMoves->availableMoveRook(tile, availableMovesArray, max, board);
        break;
    case knight:
        availableMoves->availableMoveKnight(tile, availableMovesArray, max, board);
        break;
    case king:
        availableMoves->availableMoveKing(tile, availableMovesArray, max, board);
        break;
    case queen:
        availableMoves->availableMoveQueen(tile, availableMovesArray, max, board);
        break;
    case bishop:
        availableMoves->availableMoveBishop(tile, availableMovesArray, max, board);
        break;
    }

    board->displayTiles();
    setAvailableMoves();
}

void GameEngine::prepareNewMove()
{
    fill_n(availableMovesArray, 60, NULL);
    max = 0;
}

void GameEngine::selectingMove(Tile *tile)
{
    int tileNum = tile->tileNum;
    const bool isAvailableMoveSquare = board->tiles[availableMovesArray[tileNum] / 8][availableMovesArray[tileNum] % 8]->piece == none;
    for (int i = 0; i < 60 && availableMovesArray[i] != 0; i++)
    {
        int availableMove = availableMovesArray[i];
        if (availableMove == tileNum)
        {
            doMove(tile);
        }
    }
    board->displayTiles();
}

/**
 * Move this->selectedTile's piece to param tile
 */
void GameEngine::doMove(Tile *tile)
{
    Piece selectedTilePiece = selectedTile->piece;

    // Capturing
    if (tile->piece != none && tile->pieceColor != selectedTile->pieceColor)
    {
        capturePiece(selectedTile, tile);
    }

    tile->setPiece(selectedTilePiece, turn);
    selectedTile->setPiece(none, turn);

    turn = turn == white
               ? black
               : white;
    prepareNewMove();
}

void GameEngine::capturePiece(Tile *fromTile, Tile *toTile)
{
    Player *playerWhoLostPiece = toTile->pieceColor == player1->pieceColor
                                     ? player1
                                     : player2;
    Player *playerToAddPointsTo = fromTile->pieceColor == player1->pieceColor
                                      ? player1
                                      : player2;
    playerWhoLostPiece->addPieceToLostPieces(toTile->piece);
    playerToAddPointsTo->addPointsToPlayer(toTile->piece);
}

bool GameEngine::isGameOver()
{
}

void GameEngine::setAvailableMoves()
{
    for (int i = 0; i < max; i++)
    {
        board->tiles[availableMovesArray[i] / 8][availableMovesArray[i] % 8]->setStyleSheet("QLabel {background-color: orange;}");
    }
}
