#include "../headers/available-moves.h"

AvailableMoves::AvailableMoves() {}

/**
 *  @todo en passant movement
 */
int AvailableMoves::availableMovePawn(Tile *tile, int availableMoves[], int &max, Board *board)
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

int AvailableMoves::availableMoveRook(Tile *tile, int availableMoves[], int &max, Board *board)
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

int AvailableMoves::availableMoveKnight(Tile *tile, int availableMoves[], int &max, Board *board)
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

int AvailableMoves::availableMoveKing(Tile *tile, int availableMoves[], int &max, Board *board)
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

int AvailableMoves::availableMoveQueen(Tile *tile, int availableMoves[], int &max, Board *board)
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
int AvailableMoves::availableMoveBishop(Tile *tile, int availableMoves[], int &max, Board *board)
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