#include "sort.h"

void menu(char* OPTIONS, int* ARRAY, int ARRAY_LEN, cnt* COUNTER);
void init(int ARRAY[], int ARRAY_LEN, int STEP, int RANGE);
void print_array(int ARRAY[], int ARRAY_LEN);
void random_array(int* ARRAY,char* SORT_OPTION, FILE* RESULT_FILE);
void semi_sorted_array(int* ARRAY,char* SORT_OPTION, FILE* RESULT_FILE);
void semi_inversed_sorted_array(int* ARRAY,char* SORT_OPTION, FILE* RESULT_FILE);
void repeated_numbers_array(int* ARRAY,char* SORT_OPTION, FILE* RESULT_FILE);