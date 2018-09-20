#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

//struct used for the double linked list;
typedef struct Node{       
    struct Node *previous;
    char word[30];
    struct Node *next;
}node; 

//Headers of the implemented functions;
char* strsub(char* txt, int init_i, int final_i);

node** split_text(char* txt, node** cursor);

void print_text(node** li);

void remove_word(node** cursor, node** beg_txt, node** end_txt);

void move_cursor_to(node** cursor, int move_cnt);

void move_cursor_to_begin(node** cursor,node** beg);

void move_cursor_to_end(node** cursor,node** end);

void insert_before(node** cursor, node** beg_txt,  char* word);

void insert_after(node** cursor, node** end_txt, char* word);

void replace(node** cursor, char* word);

int search(node** first,node** cursor, char* word);
