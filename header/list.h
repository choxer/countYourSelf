//
// Created by rooty on 1/29/18.
//

#ifndef COUNTYOURSELF_LIST_H
#define COUNTYOURSELF_LIST_H

#include "datastructures.h"

int insertInDVList(tHabit *Neu);

tHabit *removeFromDVList(char *tHabitName);

int listHabits();

int listOneHabit(tHabit *tmpHabit);

#endif //COUNTYOURSELF_LIST_H
