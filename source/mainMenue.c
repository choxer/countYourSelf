//
// Created by rooty on 1/27/18.
//
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "../header/mainMenue.h"

int printMainMenue(){
    int choiceStd;

    char *mainMenueTitel[10];
        mainMenueTitel[0] = "show habits";
        mainMenueTitel[1] = "show today";
        mainMenueTitel[2] = "show current month";
        mainMenueTitel[3] = "default";
        mainMenueTitel[4] = "default";
        mainMenueTitel[5] = "default";
        mainMenueTitel[6] = "preferences";
        mainMenueTitel[7] = "Sortieren";
        mainMenueTitel[8] = "Auflisten";
        mainMenueTitel[9] = "Programm beenden";

    printCounted();

    stdMenue("|| m a i n  m e n u e  ||\n", mainMenueTitel, 9);
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

        for(int i = 0; i <= numberOfPoints; i++){
            printf("|  %2i. ", i+1);
            printf("%s", *(menuPoints + i));
            printf("\n");
        }
        printf("|\n|| ||| WAHL: ");
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