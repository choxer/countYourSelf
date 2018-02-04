//
// Created by rooty on 1/29/18.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header/datastructures.h"
#include "../header/tools.h"

int load(){
    FILE *data = fopen("../database.txt", "rt");
    char *zeile = calloc( 151, sizeof(char));
    float f = 0;

    if( data ){
        do{
            printf("load database...\n");

            fscanf( data, "%150[^\n]", zeile);

            // cigaretteCounter
            if( strncmp(zeile, "<cigarettecounter>", 18) == 0 ){
                printf(">>found cigaretteCounter\n");

                size_t len = strlen( zeile + 18 ) - 19;
                //printf("%s\n", zeile);

                if ( strncmp( zeile + 18 + len, "</cigarettecounter>", 19) == 0 ){
                    char *cigarettecounter = calloc( len + 1, sizeof(char));
                    strncpy( cigarettecounter, zeile + 18, len);
                    cigaretteCounter = atoi( cigarettecounter );

                    //printf("%i\n", cigaretteCounter);
                    free(cigarettecounter);
                }
            }

            // beerCounter
            if( strncmp(zeile, "<beercounter>", 13) == 0 ){
                printf(">>found beerCounter\n");

                size_t len = strlen( zeile + 13 ) - 14;
                //printf("%s\n", zeile);

                if ( strncmp( zeile + 13 + len, "</beercounter>", 14) == 0 ){
                    char *beercounter = calloc( len + 1, sizeof(char));
                    strncpy( beercounter, zeile + 13, len);
                    beerCounter = atoi(beercounter);

                    //printf("%i\n", beerCounter);
                    free(beercounter);
                }
            }
            // sportsCounter
            if( strncmp(zeile, "<sportscounter>", 13) == 0 ){
                printf(">>found sportsCounter\n");

                size_t len = strlen( zeile + 13 ) - 14;
                //printf("%s\n", zeile);

                if ( strncmp( zeile + 13 + len, "</sportscounter>", 14) == 0 ){
                    char *sportscounter = calloc( len + 1, sizeof(char));
                    strncpy( sportscounter, zeile + 13, len);
                    sportsCounter = atoi(sportscounter);
                    //printf("%s\n", testcounter);
                }
            }

            // dateCounter
            if( strncmp(zeile, "<datecounter>", 12) == 0 ){
                printf(">>found dateCounter\n");

                size_t len = strlen( zeile + 12 ) - 13;
                //printf("%s\n", zeile);

                if ( strncmp( zeile + 12 + len, "</datecounter>", 13) == 0 ){
                    char *datecounter = calloc( len + 1, sizeof(char));
                    strncpy( datecounter, zeile + 12, len);
                    tDateCounter = atoi(datecounter);

                    //printf("%s\n", testcounter);
                }
            }

            // date
            if( strncmp(zeile, "<date>", 6) == 0 ){
                printf(">>found date\n");

                size_t len = strlen( zeile + 6 ) - 7;
                //printf("%s\n", zeile);

                if ( strncmp( zeile + 6 + len, "</date>", 7) == 0 ){
                    char *date = calloc( len + 1, sizeof(char));
                    strncpy( date, zeile + 6, len);

                    tDate *nDate = calloc( 1, sizeof(tDate));

                    getDateFromString(date, nDate);

                    currentYear[tDateCounter] = nDate;

                    //printf("%s\n", testcounter);
                }
            }

            // Abbruchbedingungen
            if( strncmp( zeile, "<ende>", 6) == 0){
                printf("<<ende>>");
                break;
            }

            if( fscanf( data, "%f", &f) == EOF){
                printf("*** End Of File ***\n");
                break;
            }

        } while( true );

        fclose(data);
        return 0;
    }
    else{
        printf("Fehler beim Laden von *database.txt*");

        fclose(data);
        return 1;
    }
}



int save(){
    FILE *data = fopen("../database.txt", "w");

    if( data ){
        fputs( "<anfang>\n", data);

        // date
        char Dnr[5];
        snprintf(Dnr, 5, "%d", tDateCounter);
        fputs("<datecounter>", data);
        fputs(Dnr, data);
        fputs("</datecounter>\n", data);
        printf(">> datecounter gespeichert..\n");

        char day[5];
        char month[5];
        char year[5];
        snprintf(day, 5, "%d", currentYear[tDateCounter]->day);
        snprintf(month, 5, "%d", currentYear[tDateCounter]->month);
        snprintf(year, 5, "%d", currentYear[tDateCounter]->year);
        fputs("<date>", data);

        fputs(day, data);
        fputs(".", data);

        fputs(month, data);
        fputs(".", data);

        fputs(year, data);

        fputs("</date>\n", data);
        printf(">> date gespeichert..\n");

        // money
/*
        fputs("<moneyin>", data);

        fputs("</moneyin>", data);


        fputs("<moneyout>", data);

        fputs("</moneyout>", data);
*/
        // cigaretteCounter
        char Cnr[5];
        snprintf(Cnr, 5, "%d", cigaretteCounter);
        fputs( "<cigarettecounter>", data);
        fputs( Cnr, data);
        fputs( "</cigarettecounter>\n", data);
        printf(">> cigarettecounter gespeichert..\n");

        // beerCounter
        char Bnr[5];
        snprintf(Bnr, 5, "%d", beerCounter);
        fputs( "<beercounter>", data);
        fputs( Bnr, data);
        fputs( "</beercounter>\n", data);
        printf(">> beercounter gespeichert..\n");

        // sportsCounter
        char Snr[5];
        snprintf(Snr, 5, "%d", sportsCounter);
        fputs( "<sportscounter>", data);
        fputs( Snr, data);
        fputs( "</sportscounter>\n", data);
        printf(">> sportscounter gespeichert..\n");


        fputs( "<ende>\n", data);

        fclose(data);
        return 0;
    }
    else{
        printf("Fehler beim Laden von *database.txt*");

        fclose(data);
        return 1;
    }

}