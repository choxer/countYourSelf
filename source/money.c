//
// Created by rooty on 2/4/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructures.h"
#include "../header/money.h"
#include "../header/mainMenue.h"
#include "../header/tools.h"

float total = 0;


double showTotal(){

    printf("\n\ntotal: %.2f", total);
}

int modMoney(){
    int choice = 0;
    float betrag = 0;

    int loop = 0;

    char *menuepoints[3];
    menuepoints[0] = "einnahme";
    menuepoints[1] = "ausgabe";
    menuepoints[2] = "back";

    do {
        choice = stdMenue("|| ||| ## G E L D ##    |\n|                       |\n", menuepoints, 3);

        printf("|| total: %2.f\n", total);

        if (choice == 0) {
            printf("||\n||     Betrag: ");
            scanf("%2f", &betrag);
            clearBuffer();

            total += betrag;

            printf("||  Einzahlung von %.2f€ bestaetigt..\n", betrag);
            printf("||  total: %.2f€\n", total);
        } else if (choice == 1) {
            printf("||\n||      Betrag: ");
            scanf("%2f", &betrag);
            clearBuffer();

            total -= betrag;

            printf("||  Auszahlung von %.2f€ bestaetigt..\n", betrag);
            printf("||  total: %.2f€\n", total);
        }
        if(choice == 2){
            return 0;
        }
        printf("\n");
    }while (!loop);
}

