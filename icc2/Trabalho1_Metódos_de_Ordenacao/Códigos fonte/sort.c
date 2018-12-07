#include "sort.h"


void bubble_sort(int a[], int len, cnt* counter){
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
            counter->comparacoes ++;
            if (a[j] > a[j + 1]){ 
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                counter->atribuicoes += 3;
            }
        }
    }
}



void selection_sort(int* a, int len, cnt* counter){ 
    /*
    Selection sort
        #Descrição
            Percorre o vetoor até achar a posição do menor valor e troca esse valor
            com o da posição i, este que começa no 0;
        #Complexidade
            Tempo: 
                worst:O(n²)
                best:Ω(n²)
    */ 
    int i, j, min, temp;
    for (i = 0; i < (len-1); i++) 
    {
        min = i; 
        for (j = (i+1); j < len; j++) {
            counter->comparacoes++;
            if(a[j] < a[min]) 
                min = j;
        }
        
        counter->comparacoes++;
        if (a[i] != a[min]) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            counter->atribuicoes += 3;
        }
    }
}



void cocktail_sort(int a[], int len, cnt* counter){
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
            counter->comparacoes ++;
            if (a[i] > a[i + 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                swapped = 0;
                counter->atribuicoes += 3;
            }
        }
        top--; //tirando a parte ordenada

        for(int i = top ; i > bottom ; i--){
            counter->comparacoes ++;
            if (a[i] < a[i - 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                swapped = 0; 
                counter->atribuicoes += 3;
            }
        }
        bottom++; //tirando a parte ordenada 
    }
}


void insertion_sort(int a[], int len, cnt* counter){
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
       counter->atribuicoes ++;
       
       for(j = i - 1; j >= 0 && (temp < a[j]); j--){
           counter->comparacoes++;
           a[j + 1] = a[j];
           counter->atribuicoes++;
       }
       a[j + 1] = temp;
      counter->atribuicoes++; 
   }
}



void merge_sort(int a[], int beg, int end, cnt* counter){
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

        merge_sort(a, beg, mid, counter);
        merge_sort(a, mid+1, end, counter);
        merge(a, beg, mid, end, counter);
    }
}
void merge(int a[], int beg, int mid, int end, cnt* counter){
    int beg1 = beg, beg2 = mid+1, begAux = 0, tam = end-beg+1;
    int *temp;
    temp = (int*)malloc(tam * sizeof(int));

    while(beg1 <= mid && beg2 <= end){
        counter->comparacoes ++;
        if(a[beg1] < a[beg2]) {
            temp[begAux] = a[beg1];
            counter->atribuicoes++;
            beg1++;
        }
        else{
            temp[begAux] = a[beg2];
            counter->atribuicoes++;
            beg2++;
        }
        begAux++;
    }

    while(beg1 <= mid){  //Caso ainda haja elementos na primeira metade
        temp[begAux] = a[beg1];
        counter->atribuicoes++;
        begAux++;
        beg1++;
    }

    while(beg2 <= end) {   //Caso ainda haja elementos na segunda metade
        temp[begAux] = a[beg2];
        counter->atribuicoes++;
        begAux++;
        beg2++;
    }

    for(begAux = beg; begAux <= end; begAux++){    //Move os elementos de volta para o a original
        a[begAux] = temp[begAux-beg];
        counter->atribuicoes++;
    }
    
    free(temp);
}



void heap_sort(int a[], int len, cnt* counter){
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
        heap(a, i, len-1, counter);
    }
    for (i = len-1; i >= 1; i--){
        aux = a[0];
        a [0] = a [i];
        a [i] = aux;
        counter->atribuicoes += 3;
        heap(a, 0, i - 1, counter);
    }
}
void heap(int a[], int i, int f, cnt* counter){
    int aux = a[i];
    counter->atribuicoes ++;
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            counter->comparacoes++;
            if(a[j] < a[j + 1]){
                j = j + 1;
            }
        }
        counter->comparacoes++;
        if(aux < a[j]){
            a[i] = a[j];
            counter->atribuicoes++;
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    a[i] = aux;
    counter->atribuicoes++;
}

void quick_sort(int *a, int left, int right, cnt* counter) {
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
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
    counter->atribuicoes ++;
    while(i <= j) {
        while(a[i] < x && i < right) {
            counter->comparacoes ++;
            i++;
        }
        while(a[j] > x && j > left) {
            counter->comparacoes ++;
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            counter->atribuicoes += 3;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j, counter);
    }
    if(i < right) {
        quick_sort(a, i, right, counter);
    }
}



void bubble_sentinel(int* a, int n, cnt* counter){
    int i, j, temp, ultima_troca;
    int flag_troca = 0;
    int sentinela = n-1;
    while(sentinela > 0){
        flag_troca = 0;
        for (j = 0; j < sentinela; j++){  
            counter->comparacoes++;
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                counter->atribuicoes += 3;
                ultima_troca = j;
                flag_troca = 1;
            }
            }
            if(flag_troca == 0) break;
            sentinela = ultima_troca;				
   	}
}