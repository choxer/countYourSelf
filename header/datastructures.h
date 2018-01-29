//
// Created by rooty on 1/27/18.
//
#ifndef UNTITLED1_DATASTRUCTURES_H
#define UNTITLED1_DATASTRUCTURES_H


typedef struct sHabit{
    // description of habit
    char *name;

    // counter
    int counter;

    // pointer for 'DoppeltVerketteteListe'
    struct sHabit *next;
    struct sHabit *prev;

    // pointer on tDate
    struct sDate *currentDate;

    // 0 = neutral; 1 = positiv; -1 = negativ
    int asses;

} tHabit;

typedef struct sDate{
    int day;

    int month;

    int year;

} tDate;


// habit[0] = cigarretes
// habit[1] = beer
// habit[2] = high%
// habit[3] = otto
// habit[4] = sports

// maybe put year in an array of Years
// tDate currentYear[365];

extern int habitCounter;

extern int cigaretteCounter;
extern int beerCounter;
extern int sportsCounter;
extern int highpercentCounter;
extern int emmaCounter;

extern tHabit *FirstHabit;
extern tHabit *LastHabit;

#endif //UNTITLED1_DATASTRUCTURES_H
