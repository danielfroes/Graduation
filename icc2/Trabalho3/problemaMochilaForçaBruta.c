
#include <stdio.h>

typedef struct {
    float peso;
    float valor;
} item;

int main()
{
    float capacidade = 14.0;
    item elems[] = {{2.0, 7.0}, {3.0, 11.0}, {1.0, 5.0}, {4.0, 15.0}, {6.0, 12.0}, 
       {4.0, 13.0}, {2.0, 11.0}};
    
    int i;
    int n = 7;
    
    int pega[n];
    float melhor_valor = 0.0;
    
    int opcoes[] = {2, 2, 2, 2, 2, 2, 2};

    int sol[] = {0, 0, 0, 0, 0, 0, 0};
    
    while(1) {
        float peso = 0.0;
        float valor = 0.0;
        for(i = 0; i < n; i++) {
            if(sol[i] == 1) {
                peso += elems[i].peso;
                valor += elems[i].valor;
            }
        }
        if (peso <= capacidade) {
            if (valor > melhor_valor) {
                melhor_valor = valor;
                for (i = 0; i < n; i++) {
                    pega[i] = sol[i];
                }
            }
        } 
        printf("\n");
        i = 0;
        sol[i]++;
        while(i < n && sol[i] >= opcoes[i]) {
            sol[i] = 0;
            i++;
            if (i < n) {
                sol[i]++;
            }
        }
        if (i >= n) {
            break;
        }
    }
    
    printf("melhor valor: %f", melhor_valor);
    printf("solucao: ");
    for(i = 0; i < n; i++) {
        if (pega[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}