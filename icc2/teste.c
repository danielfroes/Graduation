#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int qtd;
} Elem;


typedef struct
{
    unsigned long long int comparacoes;
    unsigned long long int atribuicoes;
}Cnt;

void print_array(int a[], int len)
{
    printf("------------------------------------------\n");
    for(int i = 0 ; i < len ; i++)
        printf("posição %d : %d\n",i ,a[i]);
    printf("------------------------------------------\n");
}

void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) { 
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

int main()
{
    Cnt counter;
    int n = 1000000;
    int array[n];
    int aux;
    init(array, n, 0, n/10);
    counter.atribuicoes = 0;
    counter.comparacoes = 0;
    
    
    for(int i = 0; i < n-1 ; i++)
    {
        counter.comparacoes++;
        if(array[i] > array[i+1])
        {
            aux = array[i];
            array[i] = array[i+1];
            array[i+1]= aux;
            counter.atribuicoes+=3;
        }
    }
    
    int max = array[n-1];
    Elem* arrayAux = (Elem*) calloc(max, sizeof(Elem));
    
    for(int i = 0; i < n; i++)
    {
        if(arrayAux[array[i]].num != array[i])
        {
            arrayAux[array[i]].num = array[i];
            arrayAux[array[i]].qtd ++;
            counter.atribuicoes+=2;
        }
        else
        {
            arrayAux[array[i]].qtd++;
        }
    }
    
    for(int i = 0, j = 0; i < max; i++)
    {   
        counter.comparacoes++;
        if(arrayAux[i].num != 0)
        {   
            for(int k = 0; k < arrayAux[i].qtd; k++)
            {   
                counter.comparacoes++;
                counter.atribuicoes++;
                array[j] = arrayAux[i].num;
                j++;
            }
        }
    }
    
    print_array(array, n);
    
    printf("comparacoes: %lld\n", counter.comparacoes);
    printf("atribuicoes: %lld\n", counter.atribuicoes);
    
    return 0;
}