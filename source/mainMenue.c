//
// Created by rooty on 1/27/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "../header/mainMenue.h"
#include "../header/timeStructure.h"
#include "../header/money.h"

int printMainMenue(){
    int choiceStd;

    char *mainMenueTitel[9];
        mainMenueTitel[0] = "show habits        ";
        mainMenueTitel[1] = "show today         ";
        mainMenueTitel[2] = "show current week  ";
        mainMenueTitel[3] = "show current month ";
        mainMenueTitel[4] = "money              ";
        mainMenueTitel[5] = NULL;
        mainMenueTitel[6] = "preferences        ";
        mainMenueTitel[7] = "date";
        mainMenueTitel[8] = "save               ";

    printCounted();


    printf("| ");
    showDate();

    printf("| ");
    showTotal();

    stdMenue("|\n|| m a i n   m e n u e ||\n|                       |\n", mainMenueTitel, 9);
}

int stdMenue(char *menuTitle, char **menuPoints, int numberOfPoints){
    // choosen menuePoint
    int choice = 0;
    // break from while loop
    int check  = 0;
    // stdin from user
    char input[5];

    do{
        printf("%s", menuTitle);

        for(int i = 0; i < numberOfPoints; i++){
            printf("| ");
            if(menuPoints+i){
                printf("%2i.", i+1);
                printf("%s", *(menuPoints + i));
            }
            printf("\n");
        }
        printf("|______     ____________|\n|| ||| WAHL: ");
        fgets(input, 5, stdin);
        choice = atoi(input);

        if(choice > numberOfPoints+1 || choice <= 0){
            printf("**error**: Ungueltige Eingabe..\n\n");
        }
        else{
            check = 1;
        }
    } while(!check);
    choice = choice - 1;
    return choice;
}

void printCounted(){
    // printf("\n\n\n\n\n\n\n\n");
    printf("\n|| __--~~+++|||****''''|| C O U N T E D ||''''****|||+++~~--__ ||\n");
}