#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct{
    unsigned long long int comparacoes;
    unsigned long long int atribuicoes;
}cnt;

void bubble_sort(int ARRAY[], int ARRAY_LEN, cnt* COUNTER);
void selection_sort(int ARRAY[], int ARRAY_LEN, cnt* COUNTER);
void cocktail_sort(int ARRAY[], int ARRAY_LEN, cnt* COUNTER);
void insertion_sort(int ARRAY[], int ARRAY_LEN, cnt* COUNTER);
void merge(int ARRAY[], int BEGGINING_POS, int MIDLE_POS, int ENDING_POS, cnt* COUNTER);
void merge_sort(int ARRAY[], int BEGGINING_POS, int ENDING_POS, cnt* COUNTER);
void heap(int ARRAY[], int i, int f, cnt* COUNTER);
void heap_sort(int ARRAY[], int ARRAY_LEN, cnt* COUNTER);
void quick_sort(int ARRAY[], int BEGGINING_POS, int ENDING_POS, cnt* COUNTER);
void bubble_sentinel(int* ARRAY, int ARRAY_LEN, cnt* COUNTER);