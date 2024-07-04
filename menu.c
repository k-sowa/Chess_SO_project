//
// Created by Krystian Sowa on 29/06/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void instruction() {
    char buffer[20];
    printf("************************************************************\n");
    printf("Instrukcja:\n");
    printf("************************************************************\n");
    printf("Aby się poruszać wpisz ruch w formacie: [typ figury][kolumna][wiersz]-[kolumna][wiersz]\n");
    printf("Przykład: Pd2-d4\n");
    printf("Poruszy to pionka z pola d2 na pole d4\n");
    printf("************************************************************\n");
    printf("Typy figur:\n");
    printf("P - pionek\n");
    printf("W - wieża\n");
    printf("S - skoczek\n");
    printf("G - goniec\n");
    printf("H - hetman\n");
    printf("K - król\n");
    printf("************************************************************\n");
    printf("Kolumny oznaczone są literami od a do h\n");
    printf("Wiersze oznaczone są liczbami od 1 do 8\n");
    printf("************************************************************\n");
    printf("UWAGA\n");
    printf("W tej wersji nie ma dostępnej roszady ani bicia w przelocie\n");
    printf("************************************************************\n");
    printf("Wpisz 'q' aby wrócić do menu\n");
    while (1) {
        scanf("%s", buffer);
        if (strcmp(buffer, "q") == 0) {
            return;
        }
    }
}
void displayMenu() {
    printf("************************************************************\n");
    printf("Witaj w grze szachowej!\n");
    printf("************************************************************\n");
    printf("Aby rozpocząć grę wpisz 'start'\n");
    printf("Możesz też wpisać 'instrukcja' jeśli chcesz się dowiedzieć jak poruszać się w tej implementacji gry szachowej\n");
}
void startGame(int debug_num) {
    char buffer[20];
    if (debug_num == 1) {
        printf("tryb debug gra się zaczyna!\n");
    }
    else {
        displayMenu();
        while (1) {
            scanf("%s", buffer);
            if (strcmp(buffer, "start") == 0) {
                return;
            } else if(strcmp(buffer, "instrukcja") == 0) {
                system("clear");
                instruction();
                system("clear");
                displayMenu();
            }
            else {
                printf("Wpisz 'start' aby rozpocząć grę\n");
            }
        }
    }
}

