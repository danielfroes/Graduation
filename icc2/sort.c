#include  "sort.h"

void init(int a[], int len, int step, int range) {
    int i;
    for (i = 0; i < len; i++) {
            int base = i * step;
            int offset = rand() % range;
            a[i] = base + offset;
    }
}

void print_array(int a[], int len){
    printf("------------------------------------------\n");
    for(int i = 0 ; i < len ; i++)
        printf("posição %d : %d\n",i ,a[i]);
    printf("------------------------------------------\n");
}

void bubble_sort(int a[], int len){
    /*
    Bubble sort
        #Descrição
            Faz comparações de dois em dois fazendo a troca caso o segundo seja menor que o primeiro.
            Após uma iteração do for de fora, o última posição estará ordenada, assim, repetindo o mesmo processo
            deixando as posição ordenadas de fora.
        #Complexidade
            Tempo: 
                worst:O(n²)
                best:Ω(n)
    */ 
    int aux;
    for (int i = 1; i < len; i++){
        for (int j = 0; j < len - i; j++){
            if (a[j] > a[j + 1]){
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

void selection_sort(int a[], int len){
    /*
    Selection sort
        #Descrição
            Percorre o aor até achar a posição do menor valor e troca esse valor
            com o da posição i, este que começa no 0;
        #Complexidade
            Tempo: 
                worst:O(n²)
                best:Ω(n²)
    */    
    int aux, min_pos;
    for(int i = 0; i < len-1; i++){
        min_pos = i;
        for(int j = i + 1 ; j < len ; i++ ){
            if(a[j] < a[min_pos])
                min_pos = j;
        }
        if (a[i] != a[min_pos]){
            aux = a[i];
            a[i] = a[min_pos];
            a[min_pos] = aux;
        }
    }
}

void cocktail_sort(int a[], int len){
    /*
    Cocktail sort
    #Descrição
        Bubble sort com ida e volta;
        Otimização do bubble sort;
    #Complexidade
        Tempo:
            worst:O(n²)
            best:Ω(n)
    */
    int aux, swapped = 0;
    int top = len - 1;
    int bottom  = 0;
    while (swapped  == 0 && bottom < top){
        swapped = 1;
        for (int i = bottom; i < top; i++){
            if (a[i] > a[i + 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                swapped = 0;
            }
        }
        top--; //tirando a parte ordenada

        for(int i = top ; i > bottom ; i--){
            if (a[i] < a[i - 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                swapped = 0; 
            }
        }
        bottom++; //tirando a parte ordenada 
    }
}

void insertion_sort(int a[], int len){
    /*
    Insertion_sort
        #Descrição
            Mantêm os valores anteriores à variável temporária ordenados
            inserindo os valores posteriores um por um e atualizando a variável
            temporária nessa medida;
            Bom quando se tem o vetor quase ordenado;
        #Complexidade
            Tempo:
                worst:O(n²)
                best:Ω(n)
    */
   int i, j, temp;
   for(i = 1; i < len; i++){
       temp = a[i];
       for(j = i - 1; j >= 0 && (temp < a[j]); j--){
           a[j + 1] = a[j];
       }
       a[j + 1] = temp;
   }
}

void merge_sort(int a[], int beg, int end){
    /*
    Merge sort
        #Descrição
            dividir para conquistar: ele divide o vetor em subvetores de maneira recursiva ate
            que eles tenham apenas 1 unidade, assim, intercalando todos eles enquanto se desfaz
            da pilha de recursão;
            desvantagem: ocupa espaço de memória adicional por causa do vetor temporario na função merge
        #Complexidade
            Tempo:
                worst: O(nlog(n))
                best: Ω(nlog(n))
            Armazenamento:
                0(n);
    */
    if (beg < end) {
        int mid = (end+beg)/2;

        merge_sort(a, beg, mid);
        merge_sort(a, mid+1, end);
        merge(a, beg, mid, end);
    }
}
void merge(int a[], int beg, int mid, int end){
    int beg1 = beg, beg2 = mid+1, begAux = 0, tam = end-beg+1;
    int *temp;
    temp = (int*)malloc(tam * sizeof(int));

    while(beg1 <= mid && beg2 <= end){
        if(a[beg1] < a[beg2]) {
            temp[begAux] = a[beg1];
            beg1++;
        } else {
            temp[begAux] = a[beg2];
            beg2++;
        }
        begAux++;
    }

    while(beg1 <= mid){  //Caso ainda haja elementos na primeira metade
        temp[begAux] = a[beg1];
        begAux++;
        beg1++;
    }

    while(beg2 <= end) {   //Caso ainda haja elementos na segunda metade
        temp[begAux] = a[beg2];
        begAux++;
        beg2++;
    }

    for(begAux = beg; begAux <= end; begAux++){    //Move os elementos de volta para o a original
        a[begAux] = temp[begAux-beg];
    }
    
    free(temp);
}

void heap_sort(int a[], int len){
    /*
    Heap sort
        #Descrição
            Coloca transforma o vetor em uma heap;
            Em uma heap, o maior valor é o que esta na primeira posição, assim,
            é trocado a primeira posição com a ultima e repete-se, novamente,
            o procedimento para transformar o vetor em uma heap 
            (agora nao contando com a ultima casa, esta que ja esta ordenaada).
        #Complexidade
            worst: O(nlog(n))
            best: Ω(nlog(n))
    */
    int i, aux;
    for(i=(len - 1)/2; i >= 0; i--){
        heap(a, i, len-1);
    }
    for (i = len-1; i >= 1; i--){
        aux = a[0];
        a [0] = a [i];
        a [i] = aux;
        heap(a, 0, i - 1);
    }
}

void heap(int a[], int i, int f){
    //parar para entender o codigo depois
    int aux = a[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(a[j] < a[j + 1]){
                j = j + 1;
            }
        }
        if(aux < a[j]){
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    a[i] = aux;
}

void quick_sort(int a[], int beg, int end) {
    /*
    Quick sort
        #Descrição
            Divide o vetor em dois a partir de um pivo, do lado esquerdo
            do pivo são colocados os valores menores a ele e do direito
            são colocados os maiores. recursivamente, repete-se essa etapa
            para ambos os subvetores;
        #Complexidade
            Tempo:
                worst: O(n²)(raro)
                best: best: Ω(nlog(n))
    */
    int pivot;
    if(end > beg){
        pivot = rearrange(a, beg, end);
        quick_sort(a, beg, pivot-1);
        quick_sort(a, pivot+1, end);
    }
}

int rearrange(int a[], int beg, int end ){
    //dar uma olhada melhor depois;
    int lft, rgt, pivot, aux;
    lft = beg;
    rgt = end;
    pivot = a[beg];
    while(lft < rgt){
        while(a[lft] <= pivot)
            lft++;
        while(a[rgt] > pivot)
            rgt--;
        if(lft < rgt){
            aux = a[lft];
            a[lft] = a[rgt];
            a[rgt] = aux;
        }
    }
    a[beg] = a[rgt];
    a[rgt] = pivot;
    return rgt;
}