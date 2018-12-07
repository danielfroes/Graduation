#include "text_editor.h"

//return a substring of a given string.
char* strsub(char* txt, int init_i, int final_i){ // return a substring of the txt[initial_index] from txt[final index]
    char* sub_string = (char*) malloc(100 * sizeof(char));
    for(int j = init_i, k = 0; j < final_i ; j++,k++){ 
        sub_string[k] = txt[j]; //copy the substring to it's own string;
    }
    return sub_string;// return it;
}
//take a string and split it words into a double linked list.
node** split_text(char* txt, node** end){
    node** first = (node**) calloc(1,sizeof(node*)); //creating the pointer to the first node of the list
    *first = (node*) calloc(1,sizeof(node*));
    (*first)->previous = NULL; //the previous node of the first node is NULL
    node* temp = *first; // temporary node

    for (int i = 0, init_i =0; i <= strlen(txt); i++){ //iterates over the text
        if(txt[i] == ' '){ // when two words are separated with a space
            strcpy(temp->word, strsub(txt,init_i,i));// return the string before the space;
            temp->next = (node*) calloc(1,sizeof(node));
            temp->next->previous = temp;
            temp = temp->next;
            init_i = i + 1; //atualizes the initial index of the next word;
        }
        else if(txt[i] == '\0'){ //if is the last character of the string 
            strcpy(temp->word,strsub(txt,init_i,i));
            temp->next = NULL; // last node points to NULL;
        }
        else if((txt[i] < 48) || (txt[i] > 57 && txt[i] < 65) || (txt[i] > 90 && txt[i] < 97) || (txt[i] > 122)){                  
        //if the character is special, means that has a separation between the word
            if(temp->previous == NULL){ //if is the first node;
                strcpy(temp->word,strsub(txt, init_i,i)); //copy the substring of the word to the one node
                temp->next = (node*) calloc(1,sizeof(node));
                temp->next->previous = temp;
                temp = temp->next; //goes to the next node;
                strcpy(temp->word,strsub(txt, i, i+1));// copy the substring of the special character   
                temp->next = (node*) calloc(1,sizeof(node));
                temp->next->previous = temp;
                temp = temp->next; //goes to the next node
                if(txt[i + 1] == ' ') //if the next character is a space, increment index, that way ignoring it;
                    i++;
                init_i = i + 1; //atualizes initial index;
            }
            else if((temp->previous->word[0] < 48) || (temp->previous->word[0] > 57 && temp->previous->word[0] < 65) || (temp->previous->word[0] > 90 && temp->previous->word[0] < 97) || (temp->previous->word[0] > 122)){
            //if the previous node is a special character;
                if((txt[i-1] < 48) || (txt[i-1] > 57 && txt[i-1] < 65) || (txt[i-1] > 90 && txt[i-1] < 97) || (txt[i-1] > 122)){
                //if the special character is followed exactly by another special character
                    strcpy(temp->word,strsub(txt, init_i,i+1)); // put the new special character into the node;
                    temp->next = (node*) calloc(1,sizeof(node));
                    temp->next->previous = temp;
                    temp = temp->next;//goes to the next node
                    if(txt[i + 1] == ' ')//if the next character is a space, increment index, that way ignoring it;
                        i++;
                    init_i = i + 1;//atualizes initial index;
                }
                else{
                    strcpy(temp->word,strsub(txt, init_i,i));   
                    temp->next = (node*) calloc(1,sizeof(node));
                    temp->next->previous = temp;
                    temp = temp->next;
                    init_i = i;
                    strcpy(temp->word,strsub(txt, init_i, init_i + 1));
                    temp->next = (node*) calloc(1,sizeof(node));
                    temp->next->previous = temp;
                    temp = temp->next;
                    if(txt[i + 1] == ' ') //if the next character is a space, increment index, that way ignoring it;
                        i++;
                    init_i = i + 1;  //atualizes initial index;
                }
            }
            else{
                strcpy(temp->word,strsub(txt, init_i,i)); //if is the first node;
                temp->next = (node*) calloc(1,sizeof(node));//copy the substring of the word to the one node
                temp->next->previous = temp;
                temp = temp->next;//goes to the next node;
                strcpy(temp->word,strsub(txt, i, i + 1));// copy the substring of the special character   
                temp->next = (node*) calloc(1,sizeof(node));
                temp->next->previous = temp;//goes to the next node
                temp = temp->next;
                if(txt[i + 1] == ' ') //if the next character is a space, increment index, that way ignoring it;
                    i++;
                init_i = i + 1;//atualizes initial index;
            }
            
        }
    }

    temp = *first; //renitializes the temporary node 

    while(temp->next != NULL){  // itarates trough the list until it reachs the last node;
        *end = temp;// initialize the node end as being the last node of the list;
        temp = temp->next;
    }
    return first; // return the first node;
}

void print_text(node** first){ // print the list following the given printing rules
    if(first == NULL)// if the list is empty, do nothing
        return;
    node* aux = *first; //initializes the auxiliar node as the first node of the list;
    while(aux != NULL){// itarates the list until it reachs its last node;
        if(aux == *first  || aux->previous->word[0] == '\n') // if is the first node or the special character equals <ENTER>, print normally
            printf("%s", aux->word);
        
        else if((aux->word[0] < 48) || (aux->word[0] > 57 && aux->word[0] < 65) || (aux->word[0] > 90 && aux->word[0] < 97) || (aux->word[0] > 122))//if the node contains any special character, print normally
            printf("%s",aux->word);
            
        else //if it's a word, print with a space before it;
            printf(" %s",aux->word);

        aux = aux->next;
    }
}

void remove_word(node** cursor, node** beg_txt, node** end_txt){ //remove the word the cursor points to;
    node* aux = *cursor; //initializes aux as the node it will be removed;
    if((*cursor)->next == NULL){ //if the cursor points to the last node;
        *cursor = (*cursor)->previous;
        *end_txt = *cursor;
        aux->previous->next = aux->next;
    }
    else if((*cursor)->previous == NULL){ //if the cursor points to the first node;
        *cursor = (*cursor)->next;
        *beg_txt = *cursor;
        aux->next->previous = aux->previous;
    }
    else if((*cursor)->previous == NULL && (*cursor)->previous == NULL){ //if the list has only one node;
        aux = *cursor;
        *cursor = NULL;
    }
    else{ // the middle cases;
        *cursor = (*cursor)->next;
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
    }
    
    free(aux); //delete the required node;
}

void move_cursor_to(node** cursor, int move_cnt){ // move the cursor n times to the right or to the left;
    if(move_cnt > 0 ){ // if move_cnt is positive, move to the right that many times;
        if((*cursor)->next != NULL){
            for(int i = 0; i < abs(move_cnt); i++)
                *cursor = (*cursor)->next;
        }   
    }
    else{ // if move_cnt is negative, move that many times to the left;
        if((*cursor)->previous != NULL){ 
            for(int i = 0; i < abs(move_cnt); i++)
                *cursor = (*cursor)->previous;
        }  
    }
}

void move_cursor_to_end(node** cursor,node** end){ //move the cursor to the last node;
    *cursor = *end;
}

void move_cursor_to_begin(node** cursor,node** beg){ //move the cursor to the first node;
    *cursor = *beg; 
}

void insert_before(node** cursor, node** first, char* word){ //insert a word or a special character before the node the cursor points at;
    node* new = (node*) calloc(1,sizeof(node)); //creates the new node;
    if(strcmp(word,"<ENTER>") == 0) //covering the <ENTER> special case;
        strcpy(word,"\n");
    strcpy(new->word,word); // copy the given word or special character;
    if((*cursor)->previous != NULL){ //cover the general case;
        new->previous = (*cursor)->previous;
        new->next = *cursor;
        (*cursor)->previous = new;
        new->previous->next = new;
    }
    else{ //covers the first node case;
        new->previous = (*cursor)->previous;
        new->next = *cursor;
        (*cursor)->previous = new;
        *first = new;
    }
}

void insert_after(node** cursor,node** last, char* word){//insert a word or a special character after the node the cursor points at;
    node* new = (node*) calloc(1,sizeof(node));//creates the new node;
    if(strcmp(word,"<ENTER>") == 0)//covering the <ENTER> special case;
        strcpy(word,"\n");
    strcpy(new->word,word); // copy the given word or special character;
    if((*cursor)->next != NULL){//cover the general case;
        new->previous = (*cursor);
        new->next = (*cursor)->next;
        (*cursor)->next = new;
        new->next->previous = new;
    }else{ //covers the last node case;
        new->previous = (*cursor);
        new->next = NULL;
        (*cursor)->next = new;
        *last = new;
    }
    
}

void replace(node** cursor, char* word){ //replace a word or special character of the node that the cursor points at;
    if(strcmp(word,"<ENTER>") == 0) // covers the <ENTER> special case;
        strcpy(word,"\n");
    strcpy((*cursor)->word,word); //replace the word;
}

int search(node** first, node** cursor, char* word){ //search the list for the first occurrence of the given word after the node the cursor points at and return its index; 
    node* aux = *first; 
    if(strcmp(word,"<ENTER>") == 0) // covers the <ENTER> special case
        strcpy(word,"\n");
    int cnt = 0;
    while(aux != *cursor){ //get the index of the cursor;
        cnt++;
        aux = aux->next;
    }
    aux = *cursor;
    while(aux != NULL){ // gets the index of the first occurrence of the given word
        if(strcmp(aux->word,word) == 0){
            return cnt; //return the index
        }
        else{
            aux = aux->next;
        }
        cnt++;//increment the index
    }
    return -1;// word was not found;
}
