//
// Created by rooty on 1/29/18.
//

#ifndef COUNTYOURSELF_LIST_H
#define COUNTYOURSELF_LIST_H

#include "datastructures.h"

int insertHabitInDVList(tHabit *Neu);

tHabit *removeHabitFromDVList(char *tHabitName);


int listHabits();

int listOneHabit(tHabit *tmpHabit);

#endif //COUNTYOURSELF_LIST_H
