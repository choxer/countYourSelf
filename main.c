#include <stdio.h>
#include <stdlib.h>

#include "header/habits.h"
#include "header/mainMenue.h"

int main() {
    int loop = 0;
    int choiceMain = 0;

    choiceMain = printMainMenue();

    do {
        switch (choiceMain) {
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
        }




    }while (!loop);
    return 0;
}