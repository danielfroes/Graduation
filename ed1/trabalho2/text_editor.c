#include "text_editor.h"



node** cria_lista(){
    node** li = (node*) calloc(1,sizeof(node*));
    if(li != NULL)
        *li = NULL;
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

