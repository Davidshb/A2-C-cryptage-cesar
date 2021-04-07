#include <stdlib.h>
#include <stdio.h>
#include "gestion_fichier.h"

char *lecture_fichier(const char *fichier)
{
    FILE *fp = fopen(fichier, "r");
    char *res = malloc(sizeof(char) * BUFFER_SIZE);
    *res = '\0';

    fgets(res, BUFFER_SIZE, fp);


    fclose(fp);

    return res;
}

int ecriture_fichier(const char *fichier, char *text)
{
    FILE *fp;
    
    fp = fopen(fichier, "w");

    fwrite(text, 1, strlen(text), fp);

    fclose(fp);
    return 0;
}