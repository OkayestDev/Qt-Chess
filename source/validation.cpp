#include "../headers/validation.h"
#include "../headers/piece.h"

Validation::Validation() {}

// int Validation::chooser(Tile *tiles)
// {
//     switch (tiles->piece)
//     {
//     case pawn:
//         flag = validatePawn(tiles);
//         break;
//     case rook:
//         flag = validateRook(tiles);
//         break;
//     case knight:
//         flag = validateKnight(tiles);
//         break;
//     case king:
//         flag = validateKing(tiles);
//         break;
//     case queen:
//         flag = validateQueen(tiles);
//         break;
//     case bishop:
//         flag = validateBishop(tiles);
//         break;
//     }

//     orange();

//     return flag;
// }

// //PAWN
// int Validation::validatePawn(Tile *tile)
// {
//     int row, col;

//     row = tile->row;
//     col = tile->col;
//     retVal = 0;

//     //White Pawn
//     if (tile->pieceColor)
//     {
//         if (row - 1 >= 0 && !tiles[row - 1][col]->piece)
//         {
//             exp[max++] = tiles[row - 1][col]->tilesNum;
//             retVal = 1;
//         }

//         if (row == 6 && !tiles[5][col]->piece && !tiles[4][col]->piece)
//         {
//             exp[max++] = tiles[row - 2][col]->tilesNum;
//             retVal = 1;
//         }

//         if (row - 1 >= 0 && col - 1 >= 0)
//         {
//             if (tiles[row - 1][col - 1]->pieceColor != tile->pieceColor && tiles[row - 1][col - 1]->piece)
//             {
//                 exp[max++] = tiles[row - 1][col - 1]->tilesNum;
//                 retVal = 1;
//             }
//         }

//         if (row - 1 >= 0 && col + 1 <= 7)
//         {
//             if (tiles[row - 1][col + 1]->pieceColor != tile->pieceColor && tiles[row - 1][col + 1]->piece)
//             {
//                 exp[max++] = tiles[row - 1][col + 1]->tilesNum;
//                 retVal = 1;
//             }
//         }
//     }
//     else
//     {
//         if (row + 1 <= 7 && !tiles[row + 1][col]->piece)
//         {
//             exp[max++] = tiles[row + 1][col]->tilesNum;
//             retVal = 1;
//         }

//         if (row == 1 && !tiles[2][col]->piece && !tiles[3][col]->piece)
//         {
//             exp[max++] = tiles[row + 2][col]->tilesNum;
//             retVal = 1;
//         }

//         if (row + 1 <= 7 && col - 1 >= 0)
//         {
//             if (tiles[row + 1][col - 1]->pieceColor != tile->pieceColor && tiles[row + 1][col - 1]->piece)
//             {
//                 exp[max++] = tiles[row + 1][col - 1]->tilesNum;
//                 retVal = 1;
//             }
//         }

//         if (row + 1 <= 7 && col + 1 <= 7)
//         {
//             if (tiles[row + 1][col + 1]->pieceColor != tile->pieceColor && tiles[row + 1][col + 1]->piece)
//             {
//                 exp[max++] = tiles[row + 1][col + 1]->tilesNum;
//                 retVal = 1;
//             }
//         }
//     }

//     return retVal;
// }

// //ROOK
// int Validation::validateRook(Tile *tile)
// {
//     int r, c;

//     retVal = 0;

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     return retVal;
// }

// //HORSE
// int Validation::validateKnight(Tile *tile)
// {
//     int r, c;
//     retVal = 0;

//     r = tile->row;
//     c = tile->col;

//     if (r - 2 >= 0 && c - 1 >= 0)
//     {
//         if (tiles[r - 2][c - 1]->pieceColor != tile->pieceColor || !tiles[r - 2][c - 1]->piece)
//         {
//             exp[max++] = tiles[r - 2][c - 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r - 2 >= 0 && c + 1 <= 7)
//     {
//         if (tiles[r - 2][c + 1]->pieceColor != tile->pieceColor || !tiles[r - 2][c + 1]->piece)
//         {
//             exp[max++] = tiles[r - 2][c + 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r - 1 >= 0 && c - 2 >= 0)
//     {
//         if (tiles[r - 1][c - 2]->pieceColor != tile->pieceColor || !tiles[r - 1][c - 2]->piece)
//         {
//             exp[max++] = tiles[r - 1][c - 2]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r - 1 >= 0 && c + 2 <= 7)
//     {
//         if (tiles[r - 1][c + 2]->pieceColor != tile->pieceColor || !tiles[r - 1][c + 2]->piece)
//         {
//             exp[max++] = tiles[r - 1][c + 2]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 2 <= 7 && c + 1 <= 7)
//     {
//         if (tiles[r + 2][c + 1]->pieceColor != tile->pieceColor || !tiles[r + 2][c + 1]->piece)
//         {
//             exp[max++] = tiles[r + 2][c + 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 2 <= 7 && c - 1 >= 0)
//     {
//         if (tiles[r + 2][c - 1]->pieceColor != tile->pieceColor || !tiles[r + 2][c - 1]->piece)
//         {
//             exp[max++] = tiles[r + 2][c - 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 1 <= 7 && c - 2 >= 0)
//     {
//         if (tiles[r + 1][c - 2]->pieceColor != tile->pieceColor || !tiles[r + 1][c - 2]->piece)
//         {
//             exp[max++] = tiles[r + 1][c - 2]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 1 <= 7 && c + 2 <= 7)
//     {
//         if (tiles[r + 1][c + 2]->pieceColor != tile->pieceColor || !tiles[r + 1][c + 2]->piece)
//         {
//             exp[max++] = tiles[r + 1][c + 2]->tilesNum;
//             retVal = 1;
//         }
//     }

//     return retVal;
// }

// //KING
// int Validation::validateKing(Tile *tile)
// {
//     int r, c;
//     retVal = 0;

//     r = tile->row;
//     c = tile->col;

//     if (r - 1 >= 0)
//     {
//         if (!tiles[r - 1][c]->piece || tiles[r - 1][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r - 1][c]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 1 <= 7)
//     {
//         if (!tiles[r + 1][c]->piece || tiles[r + 1][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r + 1][c]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (c - 1 >= 0)
//     {
//         if (!tiles[r][c - 1]->piece || tiles[r][c - 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c - 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (c + 1 <= 7)
//     {
//         if (!tiles[r][c + 1]->piece || tiles[r][c + 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c + 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r - 1 >= 0 && c - 1 >= 0)
//     {
//         if (!tiles[r - 1][c - 1]->piece || tiles[r - 1][c - 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r - 1][c - 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r - 1 >= 0 && c + 1 <= 7)
//     {
//         if (!tiles[r - 1][c + 1]->piece || tiles[r - 1][c + 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r - 1][c + 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 1 <= 7 && c - 1 >= 0)
//     {
//         if (!tiles[r + 1][c - 1]->piece || tiles[r + 1][c - 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r + 1][c - 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     if (r + 1 <= 7 && c + 1 <= 7)
//     {
//         if (!tiles[r + 1][c + 1]->piece || tiles[r + 1][c + 1]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r + 1][c + 1]->tilesNum;
//             retVal = 1;
//         }
//     }

//     return retVal;
// }

// //QUEEN
// int Validation::validateQueen(Tile *tile)
// {
//     int r, c;

//     retVal = 0;

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0 && c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0 && c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7 && c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7 && c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     return retVal;
// }

// //BISHOP
// int Validation::validateBishop(Tile *tile)
// {
//     int r, c;
//     retVal = 0;

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0 && c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r-- > 0 && c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7 && c++ < 7)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     r = tile->row;
//     c = tile->col;
//     while (r++ < 7 && c-- > 0)
//     {
//         if (!tiles[r][c]->piece)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//         }

//         else if (tiles[r][c]->pieceColor == tile->pieceColor)
//             break;

//         else if (tiles[r][c]->pieceColor != tile->pieceColor)
//         {
//             exp[max++] = tiles[r][c]->tilesNum;
//             retVal = 1;
//             break;
//         }
//     }

//     return retVal;
// }

// int Validation::check(Tile *tile)
// {
//     int r, c, flag;
//     retVal = 0;

//     return retVal;
// }

// void Validation::orange()
// {
//     int i, n;

//     for (i = 0; i < max; i++)
//         tiles[exp[i] / 8][exp[i] % 8]->setStyleSheet("QLabel {background-color: orange;}");
// }
