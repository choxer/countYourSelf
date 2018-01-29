//
// Created by rooty on 1/27/18.
//

#include "../header/habits.h"
#include "../header/mainMenue.h"
#include "../header/datastructures.h"
#include "../header/tools.h"
#include "../header/save.h"
#include <stdio.h>
#include <stdlib.h>

int cigaretteCounter = 0;
int beerCounter = 0;
int sportsCounter = 0;
int highpercentCounter = 0;
int emmaCounter = 0;


void showCigarettes(){
    double today;
    double month;

    int input = 0;
    int counter = 0;

    //printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("|| Du hast insgesamt %i Kippen geraucht...\n", cigaretteCounter);
    //printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);

    printf("|| -> Wie viele Zigaretten hast du heute geraucht?\n");
    printf("|| -> ");
    scanf("%i[^\n]", &input);
    clearBuffer();

    cigaretteCounter += input;

    printf("|   Du hast %i Zigarretten fuer heute eingegeben\n", input);
    printf("|   cigaretteCounter : %i\n", cigaretteCounter);

    save();
    waitForEnter();
}

void showBeer(){
    double today;
    double month;

    int input = 0;
    int counter = 0;

    //printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("|| Du hast insgesamt %i Bier getrunken...\n", beerCounter);
    //printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);

    printf("|| -> Wie viele Biere hast du heute getrunken?\n");
    printf("|| -> ");
    scanf("%i[^\n]", &input);
    clearBuffer();

    beerCounter += input;

    printf("|| Du hast %i Bier fuer heute eingegeben\n", input);
    printf("|| beerCounter : %i\n", beerCounter);

    save();
    waitForEnter();
}

void showHighPercent(){
    // printf("|| Du hast heute %i Kippen geraucht...\n");
    // printf("|| Du hast diesen Monat %i Kippen geraucht...\n");
}

void showSports(){
    double today;
    double month;

    char *input = calloc( 10, sizeof(char));
    int counter = 0;

    //printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("|| Du hast insgesamt %i-Mal Sport gemacht...\n", sportsCounter);
    //printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);

    printf("|| -> Hast du heute Sport gemacht??\n");
    printf("|| -> ");
    scanf("%s[^\n]", input);
    clearBuffer();

    if(input[0] == 'J' || input[0] == 'Y' || input[0] == 'j' || input[0] == 'y'){
        sportsCounter++;
    }
    printf("|| sportsCounter : %i\n", sportsCounter);

    save();
    waitForEnter();
}

void addHabit(int asses, char *name){
    tHabit *newHabit = calloc( 1, sizeof(tHabit));

    newHabit->asses = asses;
    newHabit->name = name;
    newHabit->counter = 0;
    // newHabit->currentDate = currentDate;

    // get day for index from currentDate
    // getDayFromCurrentDate
    // int day;
    // assign habit to the current Date in currentYear
    // (currentYear+day)->habit = newHabit;
}

void addHabitToDate( tHabit habit, int habitIndex){
    // currentDate->habit+habitIndex =
}

void showAllHabits(){
    int choiceHabit  = 0;

    char *habitMenueTitel[6];
        habitMenueTitel[0]  = "cigarretes";
        habitMenueTitel[1]  = "beer";
        habitMenueTitel[2]  = "high %";
        habitMenueTitel[3]  = "otto";
        habitMenueTitel[4]  = "sports";
        habitMenueTitel[5]  = "back";

    printCounted();

    choiceHabit = stdMenue("|\n|| a l l   h a b i t s ||\n|\n", habitMenueTitel, 6);

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

            break;
        case 4:
            showSports();
            break;
        case 5:
            return;
        default:
            break;
    }
}