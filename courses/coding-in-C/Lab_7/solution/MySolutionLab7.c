/*
 * File: MySolutionLab7.c
 * Description: Playlist Manager - Üben malloc, calloc
 */


#include <stdio.h>
#include <stdlib.h> // calloc malloc
#include <string.h>

int main()
{   
    char buffer[100]; // Variable zum Einlesen eines Strings
    int iNumb; // Variable zur Umwandlung des Strings in ein Integer
    printf("Enter the integer: ");

// if Bedingung: Liest eine Zeile, Speichert sie in Buffer, gibt einen Zeiger auf buffer zurück wenn korrekt, gibt NULL zurwück bei Fehler oder EOF
    if (fgets(buffer, sizeof(buffer), stdin) != NULL); //Überprüfung ob Eingabe korrekt ist
    {
        iNumb = (int) strtol(buffer, NULL, 10); // Zahl aus dem String lesen und in integer umwandeln
        printf("Entered number: %d\n", iNumb);
    }
// malloc funktion
    int *p_iNumb = malloc(sizeof *p_iNumb); // Speicher für int reservieren
    if(p_iNumb == NULL) // Fehlerüberprüfung
    {
        printf("Speicherallokation fehlgeschlagen\n");
        return 1;
    }

    *p_iNumb = iNumb;
    printf("\n%d", *p_iNumb);

    iNumb = iNumb * 2; 
    // calloc deklaration und initialisierung
    int *p_Arr = calloc(iNumb, sizeof(*p_iNumb));

    for (int i = 0; i <= iNumb; i++)
    {
        p_Arr[i] = i*i;
        printf("pArr: %d\n", p_Arr[i]);
    }

    //Speicher für neue Reservierungen freigeben
    void free(void *p_iNumb);
    void free(void *p_Arr);

    /*  Malloc: Reserviert ein einzelnen Speicherblock
        Calloc: Reserviert mehrere Speicherblöcke (wie ein Array) */
    



    return 0;



}

/*
    Differences between malloc and calloc:

    1. Initialization:
       - malloc(): does NOT initialize memory (contains garbage values)
       - calloc(): initializes all allocated memory to 0

    2. Parameters:
       - malloc(): takes 1 argument → total size in bytes
       - calloc(): takes 2 arguments → number of elements and size of each element; used for arrays
    */