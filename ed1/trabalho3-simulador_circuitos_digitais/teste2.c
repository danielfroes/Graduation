#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** Split(char* str, char*  divider ) //pega uma string e divide em um vetor de substring, de acordo com o delimitador
{
    char* token, ** matrix;

    token =  strtok(str, divider); // pega a substring ate o primeiro espaço
    matrix = (char**) calloc (100, sizeof(char*));    

    int i = 0;
    while(token != NULL) //continua o processo de passar pela string,
    {
        matrix[i] = (char*) calloc (10, sizeof(char)); 
        strcpy(matrix[i], token); //
        token = strtok(NULL, divider);
        i++;
    }

    return matrix;
}


int main()
{
    char str[20] = "oi\ntudo\nbem\nnao";


    char** strArray = Split(str, " \n");

    for (int i = 0; strArray[i] != NULL; i++)
        printf("%s\n", strArray[i]);
    return 0;
}