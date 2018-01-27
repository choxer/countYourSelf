//
// Created by rooty on 1/27/18.
//

#include "../header/habits.h"
#include "../header/mainMenue.h"
#include "../header/datastructures.h"
#include <stdio.h>
#include <stdlib.h>

void showCigarettes(){
    double today;
    double month;

    printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);
}

void showBeer(){
    printf("|| Du hast heute %f Bier getrunken...\n");
    printf("|| Du hast diesen Monat %f Bier getrunken...\n");
}

void showHighPercent(){
    // printf("|| Du hast heute %i Kippen geraucht...\n");
    // printf("|| Du hast diesen Monat %i Kippen geraucht...\n");
}

void showSports(){
    if(1){
    printf("|| Du hast heute noch keinen Sport gemacht!");
    }
    else{
    printf("|| Du hast heute %f Minuten Sport gemacht!");
    }
    // diese woche
    // disesn monat
}

void addHabit(int asses, char *name, tDate *currentDate){
    tHabit *newHabit = calloc( 1, sizeof(tHabit));

    newHabit->asses = asses;
    newHabit->name = name;
    newHabit->counter = 0;
    newHabit->currentDate = currentDate;

    // get day for index from currentDate
    // getDayFromCurrentDate
    // int day;
    // assign habit to the current Date in currentYear
    // (currentYear+day)->habit = newHabit;
}

void addHabitToDate(tDate *currentDate, tHabit habit, int habitIndex){
    // currentDate->habit+habitIndex =
}

void showAllHabits(){
    int choiceHabit  = 0;

    char *habitMenueTitel[4];
        habitMenueTitel[0]  = "ciggarretes";
        habitMenueTitel[1]  = "beer";
        habitMenueTitel[2]  = "high%";
        habitMenueTitel[3]  = "sports";

    printCounted();

    choiceHabit = stdMenue("||  Habits:\n", habitMenueTitel, 3);

    switch (choiceHabit){
        case 0:
            showCigarettes();
            break;
        case 1:
            showBeer();
            break;
        case 2:
            showHighPercent();
            break;
        case 3:
            showSports();
            break;
        default:
            break;
    }
}