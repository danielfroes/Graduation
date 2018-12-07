#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** Split(char* str, char*  divider ) //pega uma string e divide seguindo o divider escolhido, retornando um vetors com as substrings
{
    char* token;

    //strcat(str," END");
    token =  strtok(str, " ");

    char** matrix;

    matrix = (char**) calloc (10, sizeof(char*));    

       

    int i = 0;
    while(token != NULL)
    {
        matrix[i]  = (char*) calloc (20, sizeof(char));
        strcpy(matrix[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    return matrix;
}

int main()
{
    char word[100];

    scanf("%[^\n]s", word);

    char** words;


    words = Split(word," ");

    for(int j = 0; words[j] != NULL; j++)
        printf("palavra %d : %s\n", j, words[j]);
    

    return 0;
}
 

