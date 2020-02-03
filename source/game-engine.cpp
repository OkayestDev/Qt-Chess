#include <algorithm>

#include "../headers/game-engine.h"
#include "../headers/board.h"
#include "../headers/tile.h"
#include "../headers/piece-color.h"
#include "../headers/piece.h"


using namespace std;

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
        validatePawn(tile);
        break;
    case rook:
        validateRook(tile);
        break;
    case knight:
        validateKnight(tile);
        break;
    case king:
        validateKing(tile);
        break;
    case queen:
        validateQueen(tile);
        break;
    case bishop:
        validateBishop(tile);
        break;
    }

    board->displayTiles();
    setAvailableMoves();
}

void GameEngine::prepareNewMove()
{
    fill_n(availableMoves, 60, NULL);
    max = 0;
}

void GameEngine::selectingMove(Tile *tile)
{

    int tileNum = tile->tileNum;
    const bool isAvailableMoveSquare = board->tiles[availableMoves[tileNum] / 8][availableMoves[tileNum] % 8]->piece == none;
    for (int i = 0; i < 60 && availableMoves[i] != 0; i++)
    {
        int availableMove = availableMoves[i];
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
    }

    tile->setPiece(selectedTilePiece, turn);
    selectedTile->setPiece(none, turn);

    turn = turn == white
               ? black
               : white;
    prepareNewMove();
}

bool GameEngine::isGameOver()
{
}

int GameEngine::validatePawn(Tile *tile)
{
    int row, col;

    row = tile->row;
    col = tile->col;
    int retVal = 0;

    if (tile->pieceColor == PieceColor::white)
    {
        if (row - 1 >= 0 && !board->tiles[row - 1][col]->piece)
        {
            availableMoves[max++] = board->tiles[row - 1][col]->tileNum;
            retVal = 1;
        }

        if (row == 6 && !board->tiles[5][col]->piece && !board->tiles[4][col]->piece)
        {
            availableMoves[max++] = board->tiles[row - 2][col]->tileNum;
            retVal = 1;
        }

        if (row - 1 >= 0 && col - 1 >= 0)
        {
            if (board->tiles[row - 1][col - 1]->pieceColor != tile->pieceColor && board->tiles[row - 1][col - 1]->piece)
            {
                availableMoves[max++] = board->tiles[row - 1][col - 1]->tileNum;
                retVal = 1;
            }
        }

        if (row - 1 >= 0 && col + 1 <= 7)
        {
            if (board->tiles[row - 1][col + 1]->pieceColor != tile->pieceColor && board->tiles[row - 1][col + 1]->piece)
            {
                availableMoves[max++] = board->tiles[row - 1][col + 1]->tileNum;
                retVal = 1;
            }
        }
    }
    else
    {
        if (row + 1 <= 7 && !board->tiles[row + 1][col]->piece)
        {
            availableMoves[max++] = board->tiles[row + 1][col]->tileNum;
            retVal = 1;
        }

        if (row == 1 && !board->tiles[2][col]->piece && !board->tiles[3][col]->piece)
        {
            availableMoves[max++] = board->tiles[row + 2][col]->tileNum;
            retVal = 1;
        }

        if (row + 1 <= 7 && col - 1 >= 0)
        {
            if (board->tiles[row + 1][col - 1]->pieceColor != tile->pieceColor && board->tiles[row + 1][col - 1]->piece)
            {
                availableMoves[max++] = board->tiles[row + 1][col - 1]->tileNum;
                retVal = 1;
            }
        }

        if (row + 1 <= 7 && col + 1 <= 7)
        {
            if (board->tiles[row + 1][col + 1]->pieceColor != tile->pieceColor && board->tiles[row + 1][col + 1]->piece)
            {
                availableMoves[max++] = board->tiles[row + 1][col + 1]->tileNum;
                retVal = 1;
            }
        }
    }

    return retVal;
}

int GameEngine::validateRook(Tile *tile)
{
    int retVal = 0;
    int r = tile->row;
    int c = tile->col;
    while (r-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    return retVal;
}

int GameEngine::validateKnight(Tile *tile)
{
    int retVal = 0;
    int r = tile->row;
    int c = tile->col;

    if (r - 2 >= 0 && c - 1 >= 0)
    {
        if (board->tiles[r - 2][c - 1]->pieceColor != tile->pieceColor || !board->tiles[r - 2][c - 1]->piece)
        {
            availableMoves[max++] = board->tiles[r - 2][c - 1]->tileNum;
            retVal = 1;
        }
    }

    if (r - 2 >= 0 && c + 1 <= 7)
    {
        if (board->tiles[r - 2][c + 1]->pieceColor != tile->pieceColor || !board->tiles[r - 2][c + 1]->piece)
        {
            availableMoves[max++] = board->tiles[r - 2][c + 1]->tileNum;
            retVal = 1;
        }
    }

    if (r - 1 >= 0 && c - 2 >= 0)
    {
        if (board->tiles[r - 1][c - 2]->pieceColor != tile->pieceColor || !board->tiles[r - 1][c - 2]->piece)
        {
            availableMoves[max++] = board->tiles[r - 1][c - 2]->tileNum;
            retVal = 1;
        }
    }

    if (r - 1 >= 0 && c + 2 <= 7)
    {
        if (board->tiles[r - 1][c + 2]->pieceColor != tile->pieceColor || !board->tiles[r - 1][c + 2]->piece)
        {
            availableMoves[max++] = board->tiles[r - 1][c + 2]->tileNum;
            retVal = 1;
        }
    }

    if (r + 2 <= 7 && c + 1 <= 7)
    {
        if (board->tiles[r + 2][c + 1]->pieceColor != tile->pieceColor || !board->tiles[r + 2][c + 1]->piece)
        {
            availableMoves[max++] = board->tiles[r + 2][c + 1]->tileNum;
            retVal = 1;
        }
    }

    if (r + 2 <= 7 && c - 1 >= 0)
    {
        if (board->tiles[r + 2][c - 1]->pieceColor != tile->pieceColor || !board->tiles[r + 2][c - 1]->piece)
        {
            availableMoves[max++] = board->tiles[r + 2][c - 1]->tileNum;
            retVal = 1;
        }
    }

    if (r + 1 <= 7 && c - 2 >= 0)
    {
        if (board->tiles[r + 1][c - 2]->pieceColor != tile->pieceColor || !board->tiles[r + 1][c - 2]->piece)
        {
            availableMoves[max++] = board->tiles[r + 1][c - 2]->tileNum;
            retVal = 1;
        }
    }

    if (r + 1 <= 7 && c + 2 <= 7)
    {
        if (board->tiles[r + 1][c + 2]->pieceColor != tile->pieceColor || !board->tiles[r + 1][c + 2]->piece)
        {
            availableMoves[max++] = board->tiles[r + 1][c + 2]->tileNum;
            retVal = 1;
        }
    }

    return retVal;
}

int GameEngine::validateKing(Tile *tile)
{
    int retVal = 0;
    int r = tile->row;
    int c = tile->col;

    if (r - 1 >= 0)
    {
        if (!board->tiles[r - 1][c]->piece || board->tiles[r - 1][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r - 1][c]->tileNum;
            retVal = 1;
        }
    }

    if (r + 1 <= 7)
    {
        if (!board->tiles[r + 1][c]->piece || board->tiles[r + 1][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r + 1][c]->tileNum;
            retVal = 1;
        }
    }

    if (c - 1 >= 0)
    {
        if (!board->tiles[r][c - 1]->piece || board->tiles[r][c - 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c - 1]->tileNum;
            retVal = 1;
        }
    }

    if (c + 1 <= 7)
    {
        if (!board->tiles[r][c + 1]->piece || board->tiles[r][c + 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c + 1]->tileNum;
            retVal = 1;
        }
    }

    if (r - 1 >= 0 && c - 1 >= 0)
    {
        if (!board->tiles[r - 1][c - 1]->piece || board->tiles[r - 1][c - 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r - 1][c - 1]->tileNum;
            retVal = 1;
        }
    }

    if (r - 1 >= 0 && c + 1 <= 7)
    {
        if (!board->tiles[r - 1][c + 1]->piece || board->tiles[r - 1][c + 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r - 1][c + 1]->tileNum;
            retVal = 1;
        }
    }

    if (r + 1 <= 7 && c - 1 >= 0)
    {
        if (!board->tiles[r + 1][c - 1]->piece || board->tiles[r + 1][c - 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r + 1][c - 1]->tileNum;
            retVal = 1;
        }
    }

    if (r + 1 <= 7 && c + 1 <= 7)
    {
        if (!board->tiles[r + 1][c + 1]->piece || board->tiles[r + 1][c + 1]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r + 1][c + 1]->tileNum;
            retVal = 1;
        }
    }

    return retVal;
}

int GameEngine::validateQueen(Tile *tile)
{
    int retVal = 0;
    int r = tile->row;
    int c = tile->col;
    while (r-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
        {
            break;
        }

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r-- > 0 && c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r-- > 0 && c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7 && c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7 && c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    return retVal;
}

//BISHOP
int GameEngine::validateBishop(Tile *tile)
{
    int r, c;
    int retVal = 0;

    r = tile->row;
    c = tile->col;
    while (r-- > 0 && c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r-- > 0 && c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7 && c++ < 7)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    r = tile->row;
    c = tile->col;
    while (r++ < 7 && c-- > 0)
    {
        if (!board->tiles[r][c]->piece)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
        }

        else if (board->tiles[r][c]->pieceColor == tile->pieceColor)
            break;

        else if (board->tiles[r][c]->pieceColor != tile->pieceColor)
        {
            availableMoves[max++] = board->tiles[r][c]->tileNum;
            retVal = 1;
            break;
        }
    }

    return retVal;
}

void GameEngine::setAvailableMoves()
{
    for (int i = 0; i < max; i++)
    {
        board->tiles[availableMoves[i] / 8][availableMoves[i] % 8]->setStyleSheet("QLabel {background-color: orange;}");
    }
}
