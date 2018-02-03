//
// Created by rooty on 1/27/18.
//
#ifndef UNTITLED1_DATASTRUCTURES_H
#define UNTITLED1_DATASTRUCTURES_H

#define MAXHABITS 50


typedef struct sHabit{
    // description of habit
    char *name;

    // counter
    double counter;

    // pointer for 'DoppeltVerketteteListe'
    struct sHabit *next;
    struct sHabit *prev;

    // pointer on tDate
    struct sDate *currentDate;

    // 0 = neutral; 1 = positiv; -1 = negativ
    int asses;

} tHabit;

typedef struct sDate{
    // DATUM
    int day;
    int month;
    int year;

    // HABIT COUNTER
    //double cigarette;
    //double beer;
    //double highpercent;
    //double otto;
    //double sports;

    // pointer auf HABIT
        // tHabit currentHabits[MAXHABITS];
    tHabit *cigarette;
    tHabit *beer;
    tHabit *highpercent;
    tHabit *otto;
    tHabit *sports;
    tHabit *gewicht;

    // GEWICHT
    // double gewicht;

} tDate;


// habit[0] = cigarretes
// habit[1] = beer
// habit[2] = high%
// habit[3] = otto
// habit[4] = sports

// maybe put year in an array of Years
extern int tDateCounter;
tDate *currentYear[365];

extern tDate *FirstDay;
extern tDate *LastDay;



extern int habitCounter;

extern int cigaretteCounter;
extern int beerCounter;
extern int sportsCounter;
extern int highpercentCounter;
extern int emmaCounter;


extern tHabit *FirstHabit;
extern tHabit *LastHabit;


///
// MONEY
///

typedef struct sMoney{

    double amount;

    tDate *currentDay;

} tMoney;

extern double total;


#endif //UNTITLED1_DATASTRUCTURES_H
