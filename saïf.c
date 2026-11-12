/*
** EPITECH PROJECT, 2026
** saïf.c
** File description:
** Saïf.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_lyrics(const char *filepath)
{
    char line[256];
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        printf("Erreur : Impossible de trouver les paroles.\n");
        printf("(Assure-toi que le fichier '%s' existe bien)\n", filepath);
        return;
    }

    printf("\n--- Paroles ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n---------------\n");
    
    fclose(file);
}

int saif(char *args)
{
    char formatted_name[256];
    char filepath[512];
    int i = 0;

    printf("|============|\n|=== SAÏF ===|\n|== FINDER ==|\n|============|\n");

    if (args == NULL) {
        printf("\n\nComment l'utiliser ? ./saif <titre>\n");
        return (0);
    }

    printf("\nTitre : %s\n", args);

    strncpy(formatted_name, args, sizeof(formatted_name) - 1);
    formatted_name[sizeof(formatted_name) - 1] = '\0';

    /* Remplace les espaces par des tirets */
    for (i = 0; formatted_name[i] != '\0'; i++) {
        if (formatted_name[i] == ' ') {
            formatted_name[i] = '-';
        }
    }

    snprintf(filepath, sizeof(filepath), "lyrics/%s.txt", formatted_name);

    print_lyrics(filepath);

    return (0);
}

int main(int argc, char **argv)
{
    char full_title[512] = {0};
    int i = 0;

    if (argc == 1) {
        saif(NULL);
        return (0);
    }

    /* Recollement de tous les arguments (argv[1], argv[2]...) avec un espace entre chaque */
    for (i = 1; i < argc; i++) {
        strncat(full_title, argv[i], sizeof(full_title) - strlen(full_title) - 1);
        if (i < argc - 1) {
            strncat(full_title, " ", sizeof(full_title) - strlen(full_title) - 1);
        }
    }

    saif(full_title);
    return (0);
}
