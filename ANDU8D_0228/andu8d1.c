#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE 100
	

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int main() {
    char filename[MAX_LINE];
    char line[MAX_LINE];
    FILE *file;

    printf("File name: ");
    fgets(filename, MAX_LINE, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Új sor eltávolítása
    strcat(filename, ".txt");

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    printf("Kérem a nevet és neptunkódot! Ha kész, #-gel zárja le: \n");
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (line[0] == '#' && line[1] == '\n') {
            break;
        }
        fprintf(file, "%s", line);
    }

    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Hiba a fájl újranyitásakor");
        return 1;
    }

    printf("\nA fájl tartalma nagybetűvel:\n");
    while (fgets(line, MAX_LINE, file) != NULL) {
        to_uppercase(line);
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

