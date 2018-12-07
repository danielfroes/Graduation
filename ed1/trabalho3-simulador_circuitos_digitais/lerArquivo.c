#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* arq;
    arq = fopen("nome.txt", "r+");
    char palavra[300];
    char stringF[300] = "";

    while(!feof(arq)) {
        fgets(palavra, 300, arq);
        strcat(stringF, palavra);
    }
    printf("%s\n", stringF);
    
    fclose(arq);
    return 0;
}