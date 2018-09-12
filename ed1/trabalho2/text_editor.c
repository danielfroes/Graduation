#include "text_editor.h"


char* strsub(char* txt, int init_i, int final_i){
    char* sub_string = (char*) malloc(100 * sizeof(char));
    for(int j = init_i, k = 0; j < final_i ; j++,k++){
        sub_string[k] = txt[j];
    }
    return sub_string;
}

node** split_text(char* txt){

    node** first = (node**) calloc(1,sizeof(node*));
    *first = (node*) calloc(1,sizeof(node*));
    (*first)->after = NULL;
    node* temp = *first;
    int init_i = 0; 

    for (int i = 0; i <= strlen(txt); i++){
        switch(txt[i]){
            case ' ':
                temp->word = strsub(txt,init_i,i);;
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
            
            case '\n':
                temp->word = strsub(txt, init_i, i);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                temp->word = strsub(txt, i, i+1);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
                  
            case '.':
                temp->word = strsub(txt, init_i, i);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                temp->word = strsub(txt, i, i+1);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
            
            case '!':
                temp->word = strsub(txt, init_i, i);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                temp->word = strsub(txt, i, i+1);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
            
            case ',':
                temp->word = strsub(txt, init_i, i);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                temp->word = strsub(txt, i, i+1);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
            
            case ';':
                temp->word = strsub(txt, init_i, i);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                temp->word = strsub(txt, i, i+1);
                temp->next = (node*) calloc(1,sizeof(node*));
                temp->next->after = temp;
                temp = temp->next;
                init_i = i + 1;
                break;
            
            case '\0':
                temp->word = strsub(txt,init_i,i);;
                temp->next = NULL;
                break;
        }
    }

    return first;
}

void print_number(node** li){ 
    if(li == NULL)
        return;
    node* no = *li;
    while(no != NULL){
        printf("%s",no->word);
        no = no->next;
    }
}

node** create_list(){
    node** li = (node**) calloc(1,sizeof(node*));
    *li = (node*) calloc(1,sizeof(node*));
    return li;
}

int insere_lista_final(node** li, char* str){
    if(li == NULL)
        return 0;
    node* no;
    no = (node*) calloc(1,sizeof(node));
    if(no == NULL)
        return 0;
    strcpy(no->word,str);
    no->next = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->after = NULL;
        *li = no;
    }else{
        node *aux;
        aux = *li;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = no;
        no->after = aux;
    }
    return 1;
}

