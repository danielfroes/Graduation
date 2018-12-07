#include "sort_system.h"


void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
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

void random_array(int* a, char* option, FILE* file){
    int expoente; // expoente
    int n; //tamanho do vetor
    
    cnt counter; // struct contadores
    cnt sum_counter; //somatória dos contadores

    fprintf(file, "Para um vetor aleatorio\n");
    fprintf(file, "--------------------------------------------------\n");
    //vetor_aleatório;

    for( expoente = 2; expoente <= 6; expoente++ ){
        n = pow(10,expoente);
        counter.comparacoes = 0;
        counter.atribuicoes = 0;
        sum_counter.atribuicoes = 0;
        sum_counter.comparacoes = 0;
        int* a = (int*) calloc(n,sizeof(int));//aloca o vetor com o tamanho n;

        for(int i = 0; i < 5; i++){ 
            init(a, n, 0, 5*n); //inicia o vetor de acordo com a função

            menu(option, a, n, &counter);// seleciona o metodo de ordenação
            sum_counter.atribuicoes += counter.atribuicoes; //faz atribuiçoes
            sum_counter.comparacoes += counter.comparacoes; //fas a somatoria das comparações
        }

        free(a); //libera o vetor para ser alocado novamente com o tamanho n;
        
        fprintf(file,"para range %d\n",n);
        fprintf(file,"media das atribuicoes : %lld\n",sum_counter.atribuicoes/5);//printa a media das atribuições no arquivo
        fprintf(file,"media das comparacoes : %lld\n",sum_counter.comparacoes/5);//printa a media da comparações no arquivo 
        fprintf(file,"-----------------------------------------------------\n"); 
    }   
}


void semi_sorted_array(int* a, char* option, FILE* file){ // para os casos que estao quase ordenados
    int expoente; // expoente
    int n; //tamanho do vetor
    cnt counter; // struct contadores
    cnt sum_counter; //somatória dos contadores
    
    fprintf(file, "Para um vetor semi ordenado\n");
    fprintf(file, "--------------------------------------------------\n");
    //vetor_aleatório;

    for( expoente = 2; expoente <= 6; expoente++ ){
        n = pow(10,expoente);
        counter.comparacoes = 0;
        counter.atribuicoes = 0;
        sum_counter.atribuicoes = 0;
        sum_counter.comparacoes = 0;
        int* a = (int*) calloc(n,sizeof(int));//aloca o vetor com o tamanho n;

        for(int i = 0; i < 5; i++){ 
            init(a, n, 10, 100);//iniciao vetor de acordo com a função
            menu(option, a, n, &counter);// seleciona o metodo de ordenação
            sum_counter.atribuicoes += counter.atribuicoes; //faz a somatoria das atribuições
            sum_counter.comparacoes += counter.comparacoes; //fas a somatoria das comparações
        }


        fprintf(file,"para range %d\n",n);
        fprintf(file,"media das atribuicoes : %lld\n",sum_counter.atribuicoes/5);//printa a media das atribuições no arquivo
        fprintf(file,"media das comparacoes : %lld\n",sum_counter.comparacoes/5);//printa a media da comparações no arquivo 
        fprintf(file,"-----------------------------------------------------\n"); 
    }   
}

void semi_inversed_sorted_array(int* a, char* option, FILE* file){//paras os casos que estao quase inversamente ordenados
    int expoente; // expoente
    int n; //tamanho do vetor
    
    cnt counter; // struct dos contadores
    cnt sum_counter; //somatória dos contadores

    fprintf(file, "Para um vetor semi ordenado inversamente\n");
    fprintf(file, "--------------------------------------------------\n");
    //vetor_aleatório;

    for( expoente = 2; expoente <= 6; expoente++ ){
        n = pow(10,expoente);
        counter.comparacoes = 0;
        counter.atribuicoes = 0;
        sum_counter.atribuicoes = 0;
        sum_counter.comparacoes = 0;
        int* a = (int*) calloc(n,sizeof(int));//aloca o vetor com o tamanho n;

        for(int i = 0; i < 5; i++){ 
            init(a, n, -1, 100); //inicia o vetor de acordo com a função
            menu(option, a, n, &counter);// seleciona o metodo de ordenação
            sum_counter.atribuicoes += counter.atribuicoes; //faz a somatoria das atribuiçoes
            sum_counter.comparacoes += counter.comparacoes; //fas a somatoria das comparações
        }

        free(a); //libera o vetor para ser alocado novamente com o tamanho n;

        fprintf(file,"para range %d\n",n);
        fprintf(file,"media das atribuicoes : %lld\n",sum_counter.atribuicoes/5);//printa a media das atribuições no arquivo
        fprintf(file,"media das comparacoes : %lld\n",sum_counter.comparacoes/5);//printa a media da comparações no arquivo 
        fprintf(file,"-----------------------------------------------------\n"); 
    }   
}

void repeated_numbers_array(int* a, char* option, FILE* file){// para o caso do vetor com numeros repitidos
    int expoente; // expoente
    int n; //tamanho do vetor
    
    cnt counter; // struct contadores
    cnt sum_counter; //somatória dos contadores

    fprintf(file, "Para um vetor com numeros repetidos\n");
    fprintf(file, "--------------------------------------------------\n");


    for( expoente = 2; expoente <= 6; expoente++ ){
        n = pow(10,expoente);
        counter.comparacoes = 0;
        counter.atribuicoes = 0;
        sum_counter.atribuicoes = 0;
        sum_counter.comparacoes = 0;
        int* a = (int*) calloc(n,sizeof(int));//aloca o vetor com o tamanho n;

        for(int i = 0; i < 5; i++){ 
            init(a, n, 0, n/10); //inicia o vetor de acordo com a função
            menu(option, a, n, &counter);// seleciona o metodo de ordenação
            sum_counter.atribuicoes += counter.atribuicoes; //faz atribuiçoes
            sum_counter.comparacoes += counter.comparacoes; //fas a somatoria das comparações
        }

        free(a); //libera o vetor para ser alocado novamente com o tamanho n;

        fprintf(file,"para range %d\n",n);
        fprintf(file,"media das atribuicoes : %lld\n",sum_counter.atribuicoes/5);//printa a media das atribuições no arquivo
        fprintf(file,"media das comparacoes : %lld\n",sum_counter.comparacoes/5);//printa a media da comparações no arquivo 
        fprintf(file,"-----------------------------------------------------\n"); 
    }   
}

void menu(char* option, int* a, int len, cnt* counter){ 
    //seleciona o método de sorting a partir de uma string digitada pelo usuário
    if(strcmp(option,"quick") == 0)
        quick_sort(a, 0, len-1, counter);
    
    else if(strcmp(option, "bubble") == 0)
        bubble_sort(a, len, counter);

    else if(strcmp(option, "cocktail") == 0)
        cocktail_sort(a, len, counter);
    
    else if(strcmp(option, "sentinel") == 0)
        bubble_sentinel(a, len, counter);

    else if(strcmp(option, "insertion") == 0)
        insertion_sort(a, len, counter);
    
    else if(strcmp(option, "selection") == 0)
        selection_sort(a, len, counter);

    else if(strcmp(option, "merge") == 0)
        merge_sort(a, 0, len-1, counter);
    
    else if(strcmp(option, "heap") == 0)
        heap_sort(a, len, counter);
    
    else{
        printf("Erro");
        return;
    }
}