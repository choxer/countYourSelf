//
// Created by rooty on 1/27/18.
//

#ifndef COUNTYOURSELF_TOOLS_H
#define COUNTYOURSELF_TOOLS_H

#include "datastructures.h"

int askYesorNo(char[]);

void clearBuffer(void);

void printline(char, int);

void waitForEnter(void);

int getText(char *,int, char **, int);

int getNumber(char[], int, int *, int, int);

int getDateFromString(char *, tDate *date);


#endif //COUNTYOURSELF_TOOLS_H
