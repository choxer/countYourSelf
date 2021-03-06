//
// Created by rooty on 2/4/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructures.h"
#include "../header/money.h"
#include "../header/mainMenue.h"
#include "../header/tools.h"
#include "../header/list.h"

float total = 0;
tMoney *FirstMoney = NULL;
tMoney *LastMoney = NULL;

double showTotal(){

    printf("total: %.2f€\n", total);
}

int modMoney(){
    int choice = 0;
    float betrag = 0;

    int loop = 0;

    char inputStr[20];

    char *menuepoints[3];
    menuepoints[0] = "einnahme";
    menuepoints[1] = "ausgabe";
    menuepoints[2] = "liste";
    menuepoints[3] = "back";

    do {
        choice = stdMenue("|| ||| ## G E L D ##    |\n|                       |\n", menuepoints, 4);

        printf("|| total: %2.f\n", total);

        if (choice == 0) {
            printf("||\n||     Betrag: ");
            scanf("%2f", &betrag);
            clearBuffer();

            printf("||      Kommentar (opt): ");
            fgets(inputStr, 19, stdin);

            total += betrag;

            tMoney *nMoney = calloc( 1, sizeof(tMoney));
            nMoney->amount = betrag;
            nMoney->comment = inputStr;

            insertMoneyInDVList(nMoney);

            printf("||  Einzahlung von %.2f€ bestaetigt..\n", betrag);
            printf("||  total: %.2f€\n", total);
        } else if (choice == 1) {
            printf("||\n||      Betrag: ");
            scanf("%2f", &betrag);
            clearBuffer();

            printf("||      Kommentar (opt): ");
            fgets(inputStr, 19, stdin);

            total -= betrag;

            tMoney *nMoney = calloc( 1, sizeof(tMoney));
            nMoney->amount = -betrag;
            nMoney->comment = inputStr;

            insertMoneyInDVList(nMoney);

            printf("||  Auszahlung von %.2f€ bestaetigt..\n", betrag);
            printf("||  total: %.2f€\n", total);
        }
        else if(choice == 2){
            listMoney();
        }
        else if(choice == 3){
            return 0;
        }
        printf("\n");
    }while (!loop);
}
