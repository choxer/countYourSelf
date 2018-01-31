//
// Created by rooty on 1/27/18.
//

#include "../header/habits.h"
#include "../header/mainMenue.h"
#include "../header/datastructures.h"
#include "../header/tools.h"
#include "../header/save.h"
#include "../header/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int habitCounter = 0;

int cigaretteCounter = 0;
int beerCounter = 0;
int sportsCounter = 0;
int highpercentCounter = 0;
int emmaCounter = 0;

tHabit *FirstHabit = NULL;
tHabit *LastHabit = NULL;

void showCigarettes(){

    int input = 0;
    int counter = 0;

    tDate *today = calloc( 1, sizeof(tDate));

    today->day = 99;
    //today->cigarette->currentDate = today;

    tHabit *cigarette = calloc( 1, sizeof(tHabit));
    cigarette->name  = "Zigaretten";
    cigarette->asses = -1;
    //cigarette->currentDate = today;

    //printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("|| Du hast insgesamt %i Kippen geraucht...\n", cigaretteCounter);
    //printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);

    printf("|| -> Wie viele Zigaretten hast du heute geraucht?\n");
    printf("|| -> ");
    scanf("%i[^\n]", &input);
    clearBuffer();

    cigaretteCounter += input;

    cigarette->counter = input;

    printf("|   Du hast %i Zigarretten fuer heute eingegeben\n", input);
    printf("|   cigaretteCounter : %i\n", cigaretteCounter);

    insertHabitInDVList(cigarette);
    save();
    waitForEnter();
}

void showBeer(){
    double today;
    double month;

    int input = 0;
    int counter = 0;

    tHabit *beer = calloc( 1, sizeof(tHabit));
    beer->name  = "Zigaretten";
    beer->asses = -1;
    //beer->next  = highpercent;

    //printf("|| Du hast heute %f Kippen geraucht...\n", today);
    printf("||    Du hast insgesamt %i Bier getrunken...\n", beerCounter);
    //printf("|| Du hast diesen Monat %f Kippen geraucht...\n", month);

    printf("|| -> Wie viele Biere hast du heute getrunken?\n");
    printf("|| -> ");
    scanf("%i[^\n]", &input);
    clearBuffer();

    beerCounter += input;

    beer->counter = input;

    printf("||    Du hast %i Bier fuer heute eingegeben\n", input);
    printf("||    beerCounter : %i\n", beerCounter);

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

    //newHabit->counter = 0;
    // newHabit->currentDate = currentDate;

    // get day for index from currentDate
    // getDayFromCurrentDate
    // int day;
    // assign habit to the current Date in currentYear
    // (currentYear+day)->habit = newHabit;

    insertHabitInDVList(newHabit);

    habitCounter++;
}

void showAllHabits(){
    int choiceHabit  = 0;

    char *habitMenueTitel[7];
        habitMenueTitel[0]  = "cigarretes";
        habitMenueTitel[1]  = "beer";
        habitMenueTitel[2]  = "high %";
        habitMenueTitel[3]  = "otto";
        habitMenueTitel[4]  = "sports";
        habitMenueTitel[5]  = "list";
        habitMenueTitel[6]  = "back";

    listHabits();

    do {
        printCounted();

        choiceHabit = stdMenue("|\n|| a l l   h a b i t s ||\n|\n", habitMenueTitel, 7);



        switch (choiceHabit) {
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
                // showOtto();
                break;
            case 4:
                showSports();
                break;
            case 5:
                listHabits();
                break;
            case 6:
                return;
            default:
                break;
        }
    } while( true );
}