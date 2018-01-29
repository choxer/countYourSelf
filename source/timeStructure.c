//
// Created by rooty on 1/27/18.
//
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "../header/timeStructure.h"

void hour(){

    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);

    int tm_yday;

}


int actualTime()
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

    // returns: Www Mmm dd hh:mm:ss yyyy
    printf("%s\n", asctime(actTime));
}