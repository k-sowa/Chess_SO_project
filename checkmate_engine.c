//
// Created by Krystian Sowa on 29/06/2024.
//

#include "checkmate_engine.h"
#include "move_validation.h"

int isCheck(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int kingPosRow, kingPosCol;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == 'K' && board[i][j].color == color) {
                kingPosRow = i;
                kingPosCol = j;
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j].color != color && board[i][j].type != 'x') {
                if (isValidPieceMove(board[i][j].type, i, j, kingPosRow, kingPosCol, board)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/*int isCheckmate(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
    if (!isCheck(color, board)) {
        return 0;
    }
    // do zrobienia
    return 1;
}
*/
int isStalemate(char color, struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
    if (isCheck(color, board)) {
        return 0;
    }
    // do zrobienia
    return 1;
}
