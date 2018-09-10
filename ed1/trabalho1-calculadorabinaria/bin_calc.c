#include "bin_calc.h"

//find the position of the most significant bit 
int find_significant(char *bits, int len){
    for ( int i = len-1 ; i >= 0 ; i--){ //iterates from the last bit to the first
        if(bits[i] == '1')// check if the value of the bit is one, if it's true return the index (most significant bit position)
            return i;
    }
    return -1;// if the number is zero, it returns -1;
}

//put the number in a queued list
node** create_number(char * number, int number_len ){
    node** first = (node**) calloc(1,sizeof(node*)); // points to the pointer of the first node, that way ensuring that the initial addres of the list stay preserved;
    *first = (node*) calloc(1,sizeof(node));//this alocates memory for the first node in the list
    node* temp = *first; //send the adress to a temporary node that will be manipulated
    number_len = find_significant(number, number_len); // find the most significant number of the given number position;
    if(number_len != -1){ //if the number it's not zero, creates the list;
        for( int i = 0 ; i <= number_len ; i++ ){ // iterates over the binary number (until the most significant position), storing each bit in one node;
            temp->bit = number[i];
            if(i != number_len){ // ensure that the last node points to NULL (as it should)
                temp->next = (node*) calloc(1,sizeof(node*));
                temp = temp->next;
            }
        }
    }else{ //if number is zero, the list will be empty
        *first = NULL;
    }
    return first; //return the initial addres of the list;
    
}

//add the two binary numbers returning a new sum list. The sum algorithm was implemented considering the truth table of the full adder.
node** add(node** num1, node ** num2){
    int carry = '0'; //initializes the carry variable that will be needed in the sum algorithm
    node** first = (node**) calloc(1,sizeof(node)); // points to the pointer of the first node, that way ensuring that the initial addres of the list stay preserved
    *first = (node*) calloc(1,sizeof(node));//this alocates memory for the first node in the sum_list
    node* sum_ls = *first; //creates the sum list with 
    while(*num1 != NULL || *num2 != NULL){ //until both lists ends;
        if(*num1 != NULL && *num2 != NULL){ //if no number has ended yet, add the bit of the first number to the second
            if ((*num1)->bit == (*num2)->bit){ 
                sum_ls->bit = carry;
                if((*num1)->bit == '0' && carry == '1')
                    carry = '0';
                if((*num1)->bit == '1')
                    carry = '1';
            }
            else{
                if(carry == '1')
                    sum_ls->bit = '0'; 
                else
                    sum_ls->bit = '1';
            }
            *num1 = (*num1)->next; //goes to the next bit of the first number
            *num2 = (*num2)->next; //goes to the next bit of the second number
        }

        else if(*num1 == NULL){ //if the first number has ended first, the sum just counts the second number and the carry left out from the last operation
            if((*num2)->bit == carry)
                sum_ls->bit = '0';
            else{
                sum_ls->bit = '1';
                if(carry = '1')
                    carry = '0';
            }
            *num2 = (*num2)->next; //advances trough the bits of the remaining number;
        }

        else if(*num2 == NULL){ //if the second number has ended first, the sum just counts the first number and the carry left out from the last operation
            if((*num1)->bit == carry)
                sum_ls->bit = '0';
            else{
                sum_ls->bit = '1';
                if(carry = '1')
                    carry = '0';
            }
            *num1 = (*num1)->next; //advances trough the bits of the remaining number;
        }

        if(*num1 != NULL || *num2 != NULL ){ //until the both number ends, the sum will always need a new space for a the new bit, therefore the sum list requires a new node
            sum_ls->next = (node*) calloc(1,sizeof(node*));
            sum_ls = sum_ls->next;
        }else if(carry == '1'){ //if both numbers has ended and the carry variable has the value of 1, the sum list will require one last node to place that remaining carry bit 
            sum_ls->next = (node*) calloc(1,sizeof(node*));
            sum_ls = sum_ls->next; 
            sum_ls->bit = '1';   
        }
    }
    return first; //return the beginning of the sum_list
}

//print  the number and the number lenght
void print_number(node** li){ 
    if(li == NULL)
        return;
    node* no = *li;
    printf("%d ",number_len(li));
    while(no != NULL){
        printf("%c",no->bit);
        no = no->next;
    }
}

//free the space alocated to the number on memory
void free_number(node** num){ 
    if(num != NULL){
        node* Node;
        while((*num) != NULL){
            Node = *num;
            *num = (*num)->next;
            free(Node);
        }
        free(num);
    }
}

// run's trought the numbers and returns it lenght
int number_len(node** num){ 
    int cnt = 0;
    while(*num != NULL){
        cnt++;
        *num = (*num)->next;
    }
    return cnt;
}