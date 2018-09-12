#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

typedef struct Node{
    struct Node *after;
    char * word;
    struct Node *next;
}node;

char* strsub(char* txt, int init_i, int final_i);
node** split_text(char* txt);
void print_number(node** li);