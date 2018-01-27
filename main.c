#include <stdio.h>
#include <stdlib.h>

#include "header/habits.h"
#include "header/mainMenue.h"

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

    choiceMain = printMainMenue();

    }
    return 0;
}