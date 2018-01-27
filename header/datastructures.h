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

    // pointer on tDate
    struct sDate *currentDate;

    // 0 = neutral 1 = positiv -1 = negativ
    int asses;
} tHabit;

// habit[0] = cigarretes
// habit[1] = beer
// habit[2] = high%
// habit[3] = sports
tHabit habits[4];


typedef struct{
    // current Time/ Date
    struct sDate  *currentDate;
    struct sMonth *currentMonth;

    // boolean values
    int morning;
    int afternoon;
    int evening;
} tDay;

typedef struct sMonth{
    struct sDate *currentDate;

    int numberOfDays;
} tMonth;

typedef struct sDate{
    //
    int     year;
    tMonth *month;
    tDay   *day;

    // pointer to next an previous month
    struct sDate *next;
    struct sDate *prev;

    //pointer to each habit
    struct sHabit habit[4];
} tDate;

// maybe put year in an array of Years
tDate currentYear[365];

#endif //UNTITLED1_DATASTRUCTURES_H
