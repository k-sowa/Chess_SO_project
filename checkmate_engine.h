//
// Created by Krystian Sowa on 29/06/2024.
//

#ifndef CHESS_PROJEKT_CHECKMATE_ENGINE_H
#define CHESS_PROJEKT_CHECKMATE_ENGINE_H

#include "move_validation.h"

int isCheck(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]);
int isCheckmate(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]);
int isStalemate(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]);
#endif //CHESS_PROJEKT_CHECKMATE_ENGINE_H
