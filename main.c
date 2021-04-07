#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include "cesar.h"
#include "gestion_fichier.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Utilisation : %s <fichier> <clé>\n", argv[0]);
        return 0;
    }

    const char *fichier = argv[1];

    int cle = 0;

    int code_sortie = lecture_arguments(fichier, argv[2], &cle);

    switch (code_sortie)
    {
    case 1:
        perror("Vérifier que le fichier existe et qu'il soit accessible\n");
        return 1;
    case 2:
        perror("Vérifier que la clé soit un nombre compris entre 1 et 25");
        return 2;
    default:
        break;
    }

    char *text = lecture_fichier(fichier);
    int i = 0;

    while (text[i] != '\0')
    {
        if (!(text[i] >= 'A' && text[i] <= 'Z') && !(text[i] >= 'a' && text[i] <= 'z'))
        {
            perror("le message contient un caractère qui n'est pas pris en charge\n");
            fprintf(stderr, "caractère : %c colonne: %d\n", text[i], i);
            free(text);
            return 3;
        }
        i++;
    }
    char *coder = codage(text, cle);

    code_sortie = ecriture_fichier(fichier, coder);
    assert(!code_sortie);
    free(coder);
    free(text);
    return 0;
}
