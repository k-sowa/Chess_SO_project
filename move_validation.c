//
// Created by Krystian Sowa on 29/06/2024.
//

#include "move_validation.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define a_ascii 97 // znak a
#define one_ascii 49 // znak 1
#define BOARD_SIZE 8
int isValidMove(char* move, struct Piece board[BOARD_SIZE][BOARD_SIZE], int boardSide, int debug) {
    if (strlen(move) != 6 || move[3] != '-') {
        printf("Zły format ruchu.\n");
        return 0;
    }
    char type = move[0];
    int startCol = move[1] - a_ascii;
    int startRow = move[2] - '1';
    int endCol = move[4] - a_ascii;
    int endRow = move[5] - '1';
    if (move[0] != 'P' && move[0] != 'W' && move[0] != 'S' && move[0] != 'G' &&
        move[0] != 'H' && move[0] != 'K') {
        printf("Zły typ figury.\n");
        return 0;
    }
    if (boardSide == 0 && board[startRow][startCol].color == 'B') {
        printf("Próbujesz się poruszyć nie swoją figurą!\n");
        return 0;
    }
    if (boardSide == 1 && board[startRow][startCol].color == 'C') {
        printf("Próbujesz się poruszyć nie swoją figurą!\n");
        return 0;
    }
    if (move[1] < 'a' || move[1] > 'h' || move[2] < '1' || move[2] > '8' ||
        move[4] < 'a' || move[4] > 'h' || move[5] < '1' || move[5] > '8') {
        printf("Próbujesz wyjść poza plansze!\n");
        return 0;
    }
    if (board[endRow][endCol].color == board[startRow][startCol].color) {
        printf("Próbujesz zbić swoją własną figurę.\n");
        return 0;
    }

    if (debug == 1) {
        printf("typ figury: %c\n", type);
        printf("wiersz startowy: %d\n", startCol + 1);
        printf("wiersz startowy: %d\n", startRow + 1);
        printf("kolumna docelowa: %d\n", endCol + 1);
        printf("wiersz docelowy: %d\n", endRow + 1);
        if (isValidPieceMove(type, startRow, startCol, endRow, endCol, board)) {
            printf("ruch jest poprawny\n");
        } else {
            printf("ruch jest niepoprawny\n");
        }
    }
    if (!isValidPieceMove(type, startRow, startCol, endRow, endCol, board)) {
        printf("Zły ruch.\n");
        return 0;
    }
    return 1;
}

int rowDirection(int startRow, int endRow) {
    // 1 góra, -1 dół, 0 ta sama wysokość
    if (endRow > startRow) {
        return 1;
    } else if (endRow < startRow) {
        return -1; // dół
    } else {
        return 0;
    }
}
int stepDirection(int startCol, int endCol) {
    // 1 w prawo, -1 w lewo, 0 ta sama kolumna
    if (endCol > startCol) {
        return 1;
    } else if (endCol < startCol) {
        return -1;
    } else {
        return 0;
    }
}
int isBlocked(struct Piece board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol) {


    int rowDirectionValue = rowDirection(startRow, endRow);
    int stepDirectionValue = stepDirection(startCol, endCol);

    int row = startRow + rowDirectionValue;
    int col = startCol + stepDirectionValue;

    while (row != endRow || col != endCol) {
        if (board[row][col].type != 'x') {
            return 1;
        }
        row += rowDirectionValue;
        col += stepDirectionValue;
    }
    return 0;
}
int isValidPieceMove(char type, int startRow, int startCol, int endRow, int endCol, struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;

    switch (type) {
        case 'P': // Pionek
            if (abs(rowDiff) == 1 && abs(colDiff) == 0 || rowDiff == 2 && colDiff == 0 && startRow == 1) {
                return 1;
            } else if (abs(rowDiff) == 2 && abs(colDiff) == 0 && startRow == 6) {
                return 1;
            }
            break;
        case 'W': // Wieża
            if (rowDiff == 0 || colDiff == 0 && !isBlocked(board, startRow, startCol, endRow, endCol)) {
                return 1;
            }
            break;
        case 'S': // Skoczek
            // Funkcja abs zwraca wartość bezwzględną liczby
            if ((abs(rowDiff) == 2 && abs(colDiff) == 1) || (abs(rowDiff) == 1 && abs(colDiff) == 2)) {
                return 1;
            }
            break;
        case 'G': // Goniec
            if (abs(rowDiff) == abs(colDiff) && !isBlocked(board, startRow, startCol, endRow, endCol)) {
                return 1;
            }
            break;
        case 'H': // Hetman
            if ((rowDiff == 0 || colDiff == 0) || (abs(rowDiff) == abs(colDiff))) {
                return 1;
            }
            break;
        case 'K': // Król
            if (abs(rowDiff) <= 1 && abs(colDiff) <= 1) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}