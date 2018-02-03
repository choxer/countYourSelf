//
// Created by rooty on 1/29/18.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "../header/datastructures.h"
#include "../header/list.h"
#include "../header/tools.h"


int insertHabitInDVList(tHabit *Neu)
{
    tHabit *temp = FirstHabit;

    // pruefen, ob neues Listenelement existiert
    if (Neu == NULL)
        return 0;

    if (FirstHabit == NULL)
    {  // Fall 1: Liste ist leer
        printf("Liste leer...\n");
        Neu->next = Neu->prev = NULL;
        FirstHabit = LastHabit = Neu;
        return 1;
    }

    //cmpTName(FirstTeam->teamName, Neu->teamName);

    int cmp = strcmp(Neu->name, FirstHabit->name);

    if (cmp < 0)
    {  // Fall 2: vor dem ersten Element einfuegen
        printf("Vor 1. Element...\n");
        Neu->next = FirstHabit;
        Neu->prev = NULL;
        FirstHabit = FirstHabit->prev = Neu;
        return 1;
    }

    if (cmp > 0)
    {  // Fall 3: nach dem letzten Element einfuegen
        printf("nach letztem Element...\n");
        Neu->prev = LastHabit;
        Neu->next = NULL;
        LastHabit = LastHabit->next = Neu;
        return 1;
    }

    // Fall 4: zwischen zwei Listenelement einfuegen
    while (temp->next != NULL)
    {  // pruefen, ob neues Listenelement vor dem
        // naechsten Element eingefuegt werden muss
        int cmp2 = strcmp(temp->next->name, Neu->name);

        if (cmp2 > 0)
        {
            printf("zwischen zwei elemente...\n");
            Neu->next = temp->next;
            Neu->prev = temp;
            temp->next = temp->next->prev = Neu;
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

tHabit *removeHabitFromDVList(char *tHabitName)
{
    tHabit *tmp = NULL, *previous = NULL;

    // Fall 1: Liste leer?
    if (FirstHabit == NULL)
        return NULL;

    // Fall 2: Listenanfang entfernen?
    if (FirstHabit->name == tHabitName)
    {
        tmp = FirstHabit;
        FirstHabit = FirstHabit->next;
        // nur ein Element in Liste?
        if (FirstHabit == NULL)
            LastHabit = NULL;
        else
            FirstHabit->prev = NULL;
        return tmp;
    }

    // Fall 3: Listenende entfernen?
    if (LastHabit->name == tHabitName)
    {
        tmp = LastHabit;
        LastHabit = LastHabit->prev;
        LastHabit->next = NULL;
        return tmp;
    }

    // Fall 4: zu entfernendes Element suchen
    tmp = FirstHabit->next;
    while (tmp != NULL)
    {
        if (tmp->name == tHabitName)
        {
            previous = tmp->prev;
            previous->next = tmp->next;
            previous->next->prev = previous;
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int listOneHabit(tHabit *tempHabit){
    tDate *currDate = tempHabit->currentDate;
    double counter  = tempHabit->counter;
    char *name      = tempHabit->name;

    printf("Name: %s\n", name);
    printf("Counter: %.2f\n", counter);
}

int listHabits(){

    if(FirstHabit == NULL){
        printf("\nKeine Habits vorhanden!\n");
    }
    else{
        tHabit *tmpHabit = FirstHabit;
        printf("A L L E  S T A T S: \n");

        while (tmpHabit != NULL){
            listOneHabit( tmpHabit );
            tmpHabit = tmpHabit->next;
        }
        free(tmpHabit);
    }
    waitForEnter();

    return 0;
}