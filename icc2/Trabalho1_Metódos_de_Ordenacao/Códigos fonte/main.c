#include "sort_system.h"


int main(){
    char option[30];
    FILE *file = fopen("results.txt","w");
    scanf("%s",option);
    int* a = (int*) malloc(1000000 * sizeof(int));

    random_array(a,option,file);
    printf("25%%\n"); //porcentagens que aparecem no terminal a fim de indicar quanto falta para o fim da execução
    semi_sorted_array(a,option,file);
    printf("50%%\n");
    semi_inversed_sorted_array(a,option, file);
    printf("75%%\n");
    repeated_numbers_array(a,option,file);
    printf("100%%\n");
    printf("ORDENACAO CONCLUIDA\n");


    fclose(file);
    return 0;
}
