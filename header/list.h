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



int insertMoneyInDVList(tMoney *Neu);

tMoney *removeMoneyFromDVList(char *tMoneyName);

int listMoney();

int listOneMoney(tMoney *);

int listDates();

int appendInEVList(tDate *today);
int removefromEVList(tDate *today);
#endif //COUNTYOURSELF_LIST_H
