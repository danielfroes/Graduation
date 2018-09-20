#include "text_editor.h"

//return a substring of a given string.
char* strsub(char* txt, int init_i, int final_i){
    char* sub_string = (char*) malloc(100 * sizeof(char));
    for(int j = init_i, k = 0; j < final_i ; j++,k++){
        sub_string[k] = txt[j];
    }
    return sub_string;
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
            if(temp->previous == NULL){
                strcpy(temp->word,strsub(txt, init_i,i));   
                temp->next = (node*) calloc(1,sizeof(node));
                temp->next->previous = temp;
                temp = temp->next;
                strcpy(temp->word,strsub(txt, i, i+1));   
                temp->next = (node*) calloc(1,sizeof(node));
                temp->next->previous = temp;
                temp = temp->next;
                if(txt[i + 1] == ' ')
                    i++;
                init_i = i + 1;
            }
            else if((temp->previous->word[0] < 48) || (temp->previous->word[0] > 57 && temp->previous->word[0] < 65) || (temp->previous->word[0] > 90 && temp->previous->word[0] < 97) || (temp->previous->word[0] > 122)){
            //if the previous word was also a special character;
                if((txt[i-1] < 48) || (txt[i-1] > 57 && txt[i-1] < 65) || (txt[i-1] > 90 && txt[i-1] < 97) || (txt[i-1] > 122)){
                    strcpy(temp->word,strsub(txt, init_i,i+1));
                    temp->next = (node*) calloc(1,sizeof(node));
                    temp->next->previous = temp;
                    temp = temp->next;
                    if(txt[i + 1] == ' ')
                        i++;
                    init_i = i + 1;
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
                    if(txt[i + 1] == ' ')
                        i++;
                    init_i = i + 1;
                }
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
                if(txt[i + 1] == ' ')
                    i++;
                init_i = i + 1;
            }
            
        }
    }

    temp = *first;

    while(temp->next != NULL){  
        *end = temp;
        temp = temp->next;
    }
    return first;
}

void print_text(node** first){ 
    if(first == NULL)
        return;
    node* no = *first;
    while(no != NULL){
        if(no == *first  || no->previous->word[0] == '\n')
            printf("%s", no->word);
        
        else if((no->word[0] < 48) || (no->word[0] > 57 && no->word[0] < 65) || (no->word[0] > 90 && no->word[0] < 97) || (no->word[0] > 122))
            printf("%s",no->word);
            
        else
            printf(" %s",no->word);

        no = no->next;
    }
}

void remove_word(node** cursor, node** beg_txt, node** end_txt){
    node* aux = *cursor;
    if((*cursor)->next == NULL){
        *cursor = (*cursor)->previous;
        *end_txt = *cursor;
        aux->previous->next = aux->next;
    }
    else if((*cursor)->previous == NULL){
        *cursor = (*cursor)->next;
        *beg_txt = *cursor;
        aux->next->previous = aux->previous;
    }
    else if((*cursor)->previous == NULL && (*cursor)->previous == NULL){
        aux = *cursor;
        *cursor = NULL;
        free(aux);
    }
    else{
        *cursor = (*cursor)->next;
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;

    }
    
    free(aux);
}

void move_cursor_to(node** cursor, int move_cnt){
    if(move_cnt > 0 ){
        if((*cursor)->next != NULL){
            for(int i = 0; i < abs(move_cnt); i++)
                *cursor = (*cursor)->next;
        }   
    }
    else{
        if((*cursor)->previous != NULL){
            for(int i = 0; i < abs(move_cnt); i++)
                *cursor = (*cursor)->previous;
        }  
    }
}

void move_cursor_to_end(node** cursor,node** end){
    *cursor = *end;
}

void move_cursor_to_begin(node** cursor,node** beg){
    *cursor = *beg; 
}

void insert_before(node** cursor, node** first, char* word){
    node* new = (node*) calloc(1,sizeof(node));
    if(strcmp(word,"<ENTER>") == 0)
        strcpy(word,"\n");
    strcpy(new->word,word);
    if((*cursor)->previous != NULL){
        new->previous = (*cursor)->previous;
        new->next = *cursor;
        (*cursor)->previous = new;
        new->previous->next = new;
    }
    else{
        new->previous = (*cursor)->previous;
        new->next = *cursor;
        (*cursor)->previous = new;
        *first = new;
    }
}

void insert_after(node** cursor,node** last, char* word){
    node* new = (node*) calloc(1,sizeof(node));
    if(strcmp(word,"<ENTER>") == 0)
        strcpy(word,"\n");
    strcpy(new->word,word);
    if((*cursor)->next != NULL){
        new->previous = (*cursor);
        new->next = (*cursor)->next;
        (*cursor)->next = new;
        new->next->previous = new;
    }else{
        new->previous = (*cursor);
        new->next = NULL;
        (*cursor)->next = new;
        *last = new;
    }
    
}

void replace(node** cursor, char* word){
    if(strcmp(word,"<ENTER>") == 0)
        strcpy(word,"\n");
    strcpy((*cursor)->word,word);
}

int search(node** first, node** cursor, char* word){
    node* aux = *first;
    if(strcmp(word,"<ENTER>") == 0)
        strcpy(word,"\n");
    int cnt = 0;
    while(aux != *cursor){
        cnt++;
        aux = aux->next;
    }
    aux = *cursor;
    while(aux != NULL){
        if(strcmp(aux->word,word) == 0){
            return cnt;
        }
        else{
            aux = aux->next;
        }
        cnt++;
    }
    return -1;// word was not found;
}