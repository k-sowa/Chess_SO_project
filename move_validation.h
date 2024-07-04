//
// Created by Krystian Sowa on 29/06/2024.
//

#ifndef CHESS_PROJEKT_MOVE_VALIDATION_H
#define CHESS_PROJEKT_MOVE_VALIDATION_H
#define BOARD_SIZE 8
struct Piece {
    char type;
    char color;
};
int isValidMove(char* move, struct Piece board[BOARD_SIZE][BOARD_SIZE], int boardSide, int debug);
int isBlocked(struct Piece board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol);
int isValidPieceMove(char type, int startRow, int startCol, int endRow, int endCol, struct Piece board[BOARD_SIZE][BOARD_SIZE]);
int rowDirection(int startRow, int endRow);
int stepDirection(int startCol, int endCol);
#endif //CHESS_PROJEKT_MOVE_VALIDATION_H
