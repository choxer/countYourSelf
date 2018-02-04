//
// Created by rooty on 1/29/18.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header/datastructures.h"

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
                //printf("found cigaretteCounter\n");
                size_t len = strlen( zeile + 18 ) - 19;
                printf("%s\n", zeile);

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
                //printf("found beerCounter\n");

                size_t len = strlen( zeile + 13 ) - 14;
                printf("%s\n", zeile);

                if ( strncmp( zeile + 13 + len, "</beercounter>", 14) == 0 ){
                    char *beercounter = calloc( len + 1, sizeof(char));
                    strncpy( beercounter, zeile + 13, len);
                    //strtof(beercounter, )
                    //printf("%i\n", beerCounter);
                    free(beercounter);
                }
            }
            // sportsCounter
            if( strncmp(zeile, "<sportscounter>", 13) == 0 ){
                printf("found sportsCounter\n");

                size_t len = strlen( zeile + 13 ) - 14;
                printf("%s\n", zeile);

                if ( strncmp( zeile + 13 + len, "</sportscounter>", 14) == 0 ){
                    char *testcounter = calloc( len + 1, sizeof(char));
                    strncpy( testcounter, zeile + 13, len);

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



        // money

        fputs("<moneyin>", data);

        fputs("</moneyin>", data);


        fputs("<moneyout>", data);

        fputs("</moneyout>", data);

        // cigaretteCounter
        char Cnr[5];
        snprintf(Cnr, 5, "%d", cigaretteCounter);
        fputs( "<cigarettecounter>", data);
        fputs( Cnr, data);
        fputs( "</cigarettecounter>\n", data);

        // beerCounter
        char Bnr[5];
        snprintf(Bnr, 5, "%d", beerCounter);
        fputs( "<beercounter>", data);
        fputs( Bnr, data);
        fputs( "</beercounter>\n", data);

        // sportsCounter
        char Snr[5];
        snprintf(Snr, 5, "%d", sportsCounter);
        fputs( "<sportscounter>", data);
        fputs( Snr, data);
        fputs( "</sportscounter>\n", data);


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