#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

typedef struct Node{
    struct Node *after;
    char * word;
    struct Node *next;
}node;

