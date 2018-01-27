#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "../header/mainMenue.h"
#include "../header/habits.h"
=======
#include "mainMenue.h"
>>>>>>> 586430e04df3f1aa6707630ac232c86f0959d778

int main() {

    int choiceMain = 0;
<<<<<<< HEAD
    printMainMenue();

    switch (choiceMain){
        case 0:
            showAllHabits();
            break;
        case 1:
            // addHabit();
            break;
        case 2:
            // showCurrentDay();
            break;
        case 3:
            // showCurrentMonth();
=======
    choiceMain = printMainMenue();

    switch (choiceMain){
        case 0:
            showAllCategorie();
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
>>>>>>> 586430e04df3f1aa6707630ac232c86f0959d778
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;

    }
    return 0;
}