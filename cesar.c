#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "cesar.h"
#include "gestion_fichier.h"

int lecture_arguments(const char *fichier, const char *cle, int *key)
{
    FILE *file;
    if (!(file = fopen(fichier, "r+")))
        return 1;
    fclose(file);

    *key = (int)strtol(cle, NULL, 0);

    if (errno || *key < 1 || *key > 25)
        return 2;

    return 0;
}

char *codage(char *text, int cle)
{
    char *res = malloc(sizeof(char) * BUFFER_SIZE);
    char *cur = text, *tmp = res;
    int i=0;

    while (*cur != '\0')
    {
        int decal;
        if (*cur <= 'Z')
            decal = 'A';
        else
            decal = 'a';

        *tmp = (*cur - decal + cle) % 26 + decal;
        cur++;
        tmp++;
    }

    *tmp = '\0';

    return res;
}