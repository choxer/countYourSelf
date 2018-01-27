#include <stdio.h>
#include <stdlib.h>
#include "../header/mainMenue.h"
#include "../header/habits.h"

int main() {

    int choiceMain = 0;
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