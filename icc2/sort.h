#include <stdio.h>
#include <stdlib.h>

void init(int ARRAY[], int ARRAY_LEN, int STEP, int RANGE);
void print_array(int ARRAY[], int ARRAY_LEN);
void bubble_sort(int ARRAY[], int ARRAY_LEN);
void selection_sort(int ARRAY[], int ARRAY_LEN);
void coktail_sort(int ARRAY[], int ARRAY_LEN);
void insertion_sort(int ARRAY[], int ARRAY_LEN);
void merge(int ARRAY[], int BEGGINING_POS, int MIDLE_POS, int ENDING_POS);
void merge_sort(int ARRAY[], int BEGGINING_POS, int ENDING_POS);
void heap(int ARRAY[], int i, int f);// checar depois
void heap_sort(int ARRAY[], int ARRAY_LEN);
int rearrange(int ARRAY[], int BEGGINING_POS, int ENDING_POS);//checar depois
void quick_sort(int ARRAY[], int BEGGINING_POS, int ENDING_POS);
