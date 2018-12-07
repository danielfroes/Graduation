
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
    
    int sol[] = {0, 0, 0, 0, 0, 0, 0};

    float peso = 0.0;
    float melhor_valor = 0.0;

    for(i = 0; i < n; i++) {
        float melhor_custo = 0.0;
        int melhor_item = -1;
        int j;
        for(j = 0; j < n; j++) {
            if (sol[j] == 0) {
                float essecusto = elems[j].valor / elems[j].peso;
                if(essecusto > melhor_custo) {
                    melhor_custo = essecusto;
                    melhor_item = j;
                }
            }
        }
        if (peso + elems[melhor_item].peso <= capacidade) {
            printf("melhor item selecionado: %d\n", melhor_item);
            peso += elems[melhor_item].peso;
            melhor_valor += elems[melhor_item].valor;
            sol[melhor_item] = 1;
        } else {
            sol[melhor_item] = 2;
        }
    }

    printf("melhor valor: %f", melhor_valor);
    printf("solucao: ");
    for(i = 0; i < n; i++) {
        if (sol[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}￼
￼
￼
￼
￼
￼
