#include <stdio.h>
#include <stdlib.h>

#include "header/habits.h"
#include "header/mainMenue.h"
#include "header/showCurrent.h"
#include "header/tools.h"

int main() {
    int loop = 0;
    int choiceMain = 0;

    do {
        choiceMain = printMainMenue();

        switch (choiceMain) {
            case 0:
                showAllHabits();
                waitForEnter();
                break;
            case 1:
                showCurrentDay();
                break;
            case 2:
                // showCurrentMonth();
                break;
            case 3:
                //
                break;
            case 4:
                // showCurrentMonth();
                break;
            case 5:
                // showCurrentMonth();
                break;
            case 6:
                // showCurrentMonth();
                break;
            case 7:
                // showCurrentMonth();
                break;
            case 8:
                // showCurrentMonth();
                break;
            case 9:
                printf("\nshould end programm && save the data");
                break;
        }

    }while (!loop);
    return 0;
}