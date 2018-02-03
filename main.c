#include <stdio.h>
#include <stdlib.h>

#include "header/habits.h"
#include "header/mainMenue.h"
#include "header/showCurrent.h"
#include "header/tools.h"
#include "header/save.h"
#include "header/timeStructure.h"
#include "header/datastructures.h"
#include "header/money.h"

int main() {
    int loop = 0;
    int choiceMain = 0;

    // load();
    // isNewDay();

    needNewDay();

    printf("currentYear[0]: %02d.%02d.%d", currentYear[0]->day, currentYear[0]->month, currentYear[0]->year);

    showTotal();



    // actualTime();

    /*
    do {
        choiceMain = printMainMenue();

        switch (choiceMain) {
            case 0:
                showAllHabits();
                break;
            case 1:
                showCurrentDay();
                break;
            case 2:
                // showCurrentWeek();
                break;
            case 3:
                // showCurrentMonth();
                break;
            case 4:

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
                save();
                break;
            default:
                break;
        }

    }while (!loop);
    */

    return 0;
}