//
// Created by rooty on 1/27/18.
//
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../header/timeStructure.h"
#include "../header/datastructures.h"

tDate *FirstDay = NULL;
tDate *LastDay = NULL;

int tDateCounter = 0;

void hour(){

    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);

    int tm_yday;

}


tDate *actualTime()
{
    /*
    int tm_sec;          seconds,  range 0 to 59
    int tm_min;          minutes, range 0 to 59
    int tm_hour;         hours, range 0 to 23
    int tm_mday;         day of the month, range 1 to 31
    int tm_mon;          month, range 0 to 11
    int tm_year;         The number of years since 1900
    int tm_wday;         day of the week, range 0 to 6
    int tm_yday;         day in the year, range 0 to 365
    int tm_isdst;        daylight saving time
    */

    time_t now;
    time(&now);

    struct tm *actTime;
    actTime = localtime(&now);

    //printf("%02d:%02d:%02d Uhr\n", actTime->tm_hour, actTime->tm_min, actTime->tm_sec);

    //printf("Heute ist der %02d.%i.%i\n", actTime->tm_mday, actTime->tm_mon, actTime->tm_year);

    // printf("%d\n", actTime->tm_wday);

    //printf("%02d.", actTime->tm_mday);
    //printf("%02d.", actTime->tm_mon+1);
    //printf("%d\n", actTime->tm_year+1900);

    tDate *tmp = calloc( 1, sizeof(tDate));

    tmp->day   = actTime->tm_mday;
    tmp->month = actTime->tm_mon+1;
    tmp->year  = actTime->tm_year+1900;

    // returns: Www Mmm dd hh:mm:ss yyyy
    // printf("%s\n", asctime(actTime));
    return tmp;
}

int needNewDay(){
    // check if last date is actual date
    FirstDay = currentYear[0];

    tDate *temp = calloc( 1, sizeof(tDate));
    temp = actualTime();

    tDate *test = calloc( 1, sizeof(tDate));
    test->day = 99;
    test->month = 12;
    test->year = 2018;

    currentYear[1] = test;

    printf("Actual Day: %02d.%02d.%d\n", temp->day, temp->month, temp->year);
    printf("currentYear[1]: %02d.%02d.%d\n", test->day, test->month, test->year);

    // LastDay = currentYear[tDateCounter];

    LastDay = currentYear[1];

    printf("tDateCounter: %d\n", tDateCounter);

    if(FirstDay == LastDay){
        printf("Nur ein Tag...\n");
    }
    if(LastDay == temp){
        printf("Kein Neuer Tag benötigt");
        return 0;
    }
    if(LastDay != temp){

        tDate *newDate = calloc( 1, sizeof(tDate));
        currentYear[tDateCounter] = newDate;

        newDay(newDate);

        printf("newDate: %02d.%02d.%d\n", newDate->day, newDate->month, newDate->year);
    }

    free(temp);
}

int newDay(tDate *actDate){
    time_t now;
    time(&now);

    struct tm *actTime;
    actTime = localtime(&now);

    if( actDate ){
        actDate->day   = actTime->tm_mday;
        actDate->month = actTime->tm_mon+1;
        actDate->year  = actTime->tm_year+1900;

        tDateCounter++;

        return 0;
    } else{
        return 1;
    }
}