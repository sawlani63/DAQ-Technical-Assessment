#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("dump.log", "r");
    if (fp == NULL) {
        printf("Error opening file: dump.log");
        return 1;
    }

    FILE *new = fopen("output.txt", "w");
    if (new == NULL) {
        printf("Error opening file: output.txt");
        return 1;
    }

    char content[1000];
    while (fgets(content, 1000, fp)) {
        char *token = strtok(content, " #");
        fprintf(new, "%s: ", token);
        token = strtok(NULL, " #");
        token = strtok(NULL, " #");
        fprintf(new, "%s", token);
        token = strtok(NULL, " #");
        fprintf(new, "%s", token);
    }

    fclose(fp);
    fclose(new);

    return 0;
}
