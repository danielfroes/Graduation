#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node_t{
    char bit;
    struct node_t * next;
}node; //node of the list, having the information of the data and the addres of the new node

typedef struct node_t** bin; //defining type bin for abstraction reasons; 

int find_significant(char *BITS, int NUM_LENGHT); //find the position of the most significant bit 
bin create_number(char* NUMBER_VALUE, int NUMBER_LENGHT); //put the number in a queued list
void print_number(bin NUMBER); //print the number and the number lenght
bin add(bin NUMBER1, bin NUMBER2); //add the two binary numbers returning a new sum list. The sum algorithm was implemented considering the truth table of the full adder.
int number_len(bin NUMBER); //run's trought the numbers and returns it lenght
void free_number(bin NUMBER); //free the space alocated to the number on memory


