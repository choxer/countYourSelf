//
// Created by rooty on 1/27/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/tools.h"

int askYesorNo(char strQuestion[])
{
    char Input;
    do{


        printf("%s\n",strQuestion);

        scanf("%c",&Input);

        clearBuffer();

        if(Input=='y'||Input=='Y'||Input=='j'||Input=='J')
            return 1;

        if(Input=='n'||Input=='N')
            return 0;

    }while(Input||Input!='\n');

    return 0;
}

void clearBuffer(void)
{
    char dummy;
    do
    {
        scanf("%c", &dummy);
    } while(dummy != '\n');
}

void printline(char text,int anz){

    int i;
    for(i=0;i<anz;i++){

        printf("%c",text);
    }
    printf("\n");
}

void waitForEnter(void){

    //clearBuffer();
    printf("Enter druecken um fortzufahren..\n");
    char enter;
    scanf("%[^\n]",&enter);
    clearBuffer();
}

void chomp(char *str)       // KOPIERTE FUNKTION !!!!
{
    size_t p=strlen(str);
    /* '\n' mit '\0' überschreiben */
    str[p-1]='\0';
}

int getNumber(char *eingabeAufruf,int optional,int *PStruct, int von, int bis)
{
    char *Input;
    char Format[30];
    int scanErg;
    int len;

    if(PStruct == NULL)
        return 0;

    *PStruct = NULL;
    Input = calloc(4, sizeof(int));

    if(Input)
    {
        sprintf(Format, "%%%i[^\n]", 4);

        do
        {
            printf("%s", eingabeAufruf);
            scanErg = scanf(Format, Input);
            clearBuffer();
            len = strlen(Input);
            if(len>0)
            {
                *PStruct = malloc( (len+1)*sizeof(int) );
                // prüfen ob reserviert:
                if(PStruct)
                {
                    int test = 0;
                    test = atoi(Input);
                    //printf("%i\n", test);
                    *PStruct = test;
                }
                else
                {
                    free(Input);
                    return 0;
                }
            }
            else
            {
                if(optional)
                {
                    free(Input);
                    return 1;
                }
                else
                    scanErg = 0;
            }
        } while(scanErg==0);
        free(Input);
        return 1;
    }
    return 0;
}

int getText(char *prompt, int maxLen, char **Text, int allowEmpty)
{
    char *Input;
    char Format[30];
    int scanErg;
    int len;

    if(maxLen <= 0)
        return 0;
    if(Text == NULL)
        return 0;

    *Text = NULL;
    Input = calloc(maxLen+1, sizeof(char));

    if(Input)
    {
        sprintf(Format, "%%%i[^\n]", maxLen);
        do
        {
            printf("%s", prompt);
            scanErg = scanf(Format, Input);
            clearBuffer();
            len = strlen(Input);
            if(len>0)
            {
                *Text = malloc( (len+1)*sizeof(char) );
                // prüfen ob reserviert:
                if(Text)
                {
                    strcpy(*Text, Input);
                }
                else
                {
                    free(Input);
                    return 0;
                }
            }
            else
            {
                if(allowEmpty)
                {
                    free(Input);
                    return 1;
                }
                else
                    scanErg = 0;
            }
        } while(scanErg == 0);
        free(Input);
        return 1;
    }
    return 0;
}