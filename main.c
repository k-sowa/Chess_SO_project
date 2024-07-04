#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "move_validation.h"
#include "menu.h"
#include "checkmate_engine.h"
#define BOARD_SIZE 8
#define a_ascii 97 // znak a
#define h_ascii 104 // znak h
#define one_ascii 49 // znak 1
#define MAX_CAPTURES 32
#define BUFFER 100

struct Piece capturedPieces[MAX_CAPTURES];
int capturedPiecesCount = 0;


void getMove(char* move) {
    printf("\n");
    printf("Wpisz swój ruch: ");
    if (scanf("%s", move) != 1) {
        printf("Zły format.\n");
    }
}


void makeMove(struct Piece board[BOARD_SIZE][BOARD_SIZE], char* move) {
    int startCol = move[1] - a_ascii;
    int startRow = (move[2] - one_ascii);
    int endCol = move[4] - a_ascii;
    int endRow = (move[5] - one_ascii);

    if (board[startRow][startCol].type != move[0]) {
        printf("Zły typ figury.\n");
        return;
    }
    if (board[endRow][endCol].type != 'x') {
        capturedPieces[capturedPiecesCount++] = board[endRow][endCol];
    }
    struct Piece temp = board[startRow][startCol];
    board[startRow][startCol] = (struct Piece) {'x', ' '};
    board[endRow][endCol] = temp;
}

void printBoard(struct Piece board[BOARD_SIZE][BOARD_SIZE], int boardSide) {
    printf("\n");
    printf("************************************************************\n");
    if (boardSide == 0)
        printf("Tura czarnych\n");
    else
        printf("Tura białych\n");
    printf("************************************************************\n");
    printf("\n");
    // Wypisanie oznaczeń a do h na górze planszy
    printf("    ");
    for (int i = a_ascii; i <= h_ascii; i++) {
        printf(" %c ", i);
    }
    printf("\n\n");
    // Wypisanie figur na planszy
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        // Wypisanie numerów wierszy po lewej stronie planszy
        printf("%d   ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j].type);
        }
        // Wypisanie numerów wierszy po prawej stronie planszy
        printf("   %d\n", i + 1);
    }
    printf("\n    ");
    // Wypisanie oznaczeń a do h na dole planszy
    for (int i = a_ascii; i <= h_ascii; i++) {
        printf(" %c ", i);
    }
    printf("\n");

    printf("Zbite figury białych:");
    for (int i = 0; i < capturedPiecesCount; i++){
        if (capturedPieces[i].color == 'B')
        printf("%c ", capturedPieces[i].type);
    }
    printf("\n");
    printf("Zbite figury czarnych:");
    for (int i = 0; i < capturedPiecesCount; i++){
        if (capturedPieces[i].color == 'C')
        printf("%c ", capturedPieces[i].type);
    }
}

void initializeBoard(struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
    // Inicjalizacja figur na planszy
    char white_pieces[] = {'W', 'S', 'G', 'H', 'K', 'G', 'S', 'W'};
    char white_pawns[] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
    char black_pieces[] = {'W', 'S', 'G', 'H', 'K', 'G', 'S', 'W'};
    char black_pawns[] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};

    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[1][i] = (struct Piece) {white_pawns[i], 'B'};
        board[0][i] = (struct Piece) {white_pieces[i], 'B'};
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[6][i] = (struct Piece) {black_pawns[i], 'C'};
        board[7][i] = (struct Piece) {black_pieces[i], 'C'};
    }
    for (int row = 2; row <= 5; row++) {
        for (int col = 0; col < 8; col++) {
            board[row][col] = (struct Piece) {'x', ' '};
        }
    }
}

int main(void) {
    struct Piece board[BOARD_SIZE][BOARD_SIZE];
    startGame(0);
    initializeBoard(board);
    int boardSide = 1; // 1 - biali 0 - czarni
    char move[7];
    while (1) {
        char color;
        char oponent[BUFFER];
        char notOponent[BUFFER];
        printBoard(board, boardSide);
        getMove(move);
        printf("Wpisano ruch: '%s'\n", move);
        if (!isValidMove(move, board,boardSide,0)) {
            printf("Zły ruch spróbuj ponownie\n");
            continue;
        }

        makeMove(board, move);

        if (boardSide == 0) {
            color = 'B';
            strcpy(oponent, "czarnych");
            strcpy(notOponent, "biali");
        }
        else {
            color = 'C';
            strcpy(oponent, "białych");
            strcpy(notOponent, "czarni");
        }

        /*if (isCheckmate(color, board)) {
            printf("************************************************************\n");
            printf("Szach mat! Wygrali %s!\n",notOponent);
            printf("************************************************************\n");
            break;
        }
	*/
        if (isCheck(color, board)) {
            printf("************************************************************\n");
            printf("Król pionków %s jest szachowany!\n",oponent);
            printf("************************************************************\n");
        }
        boardSide = !boardSide;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    return 0;
}
