#include "text_editor.h"


int main(){

    FILE *txt_file;
    char file_name[100],txt[100000], aux[1000], option;
    int num_lines = 0, ctrl = 1;
    node** beg_txt;
    node** cursor = (node**)calloc(1,sizeof(node*));
    node** end_txt = (node**)calloc(1,sizeof(node*));
    size_t bits  = 32;
    scanf("%s",file_name);    
    strcat(file_name,".ext");
    txt_file = fopen(file_name,"r");

    while(!feof(txt_file)){
        fgets(aux,1000,txt_file);
        strcat(txt, aux);
    }
   

    beg_txt = split_text(txt, end_txt);
    
    *cursor = *beg_txt;
    
    int n;

    //print_text(beg_txt);
    //printf("\n\n");
    char* word = (char*) calloc(30,sizeof(char));
    while(ctrl){
       
        scanf("%c",&option);

        switch(option){
            case 's' : //print the text and terminate the program
                print_text(beg_txt);
                ctrl = 0;
                break;

            case 'n' : //advances the cursor to the next word
                move_cursor_to(cursor, 1);
                //printf("%s e i:%d\n",(*cursor)->word,search(beg_txt,cursor,(*cursor)->word));
                break;
            
            case 'p' : // advances the cursor to the previous word
                move_cursor_to(cursor, -1);
                //printf("%s e i:%d\n",(*cursor)->word,search(beg_txt,cursor,(*cursor)->word));
                break;
            
            case 'b' : // put the cursor to the beggining of the text
                move_cursor_to_begin(cursor, beg_txt);
                //printf("%s e i:%d\n",(*cursor)->word,search(beg_txt,cursor,(*cursor)->word));
                break;

            case 'e' : // put the cursor to the end of the text
                move_cursor_to_end(cursor, end_txt);
                //printf("%s e i:%d\n",(*cursor)->word,search(beg_txt,cursor,(*cursor)->word));
                break;
            
            case 'd' :  // remove the word that the cursor points
                remove_word(cursor,beg_txt,end_txt);
                //print_text(beg_txt); printf("\n\n");
                break;

            case 'g' : //move the cursor n times
                scanf("%d", &n);
                move_cursor_to(cursor, n);
                //printf("%s e i:%d\n",(*cursor)->word,search(beg_txt,cursor,(*cursor)->word));
                break;
            
            case 'i' : //insert a word before the word the cursor is pointing
                scanf("%s", word);
                insert_before(cursor,beg_txt,word);
                //printf("\n"); print_text(beg_txt); printf("\n\n");
                break;

            case 'r': //replace the word that the cursor is pointing to;
                scanf("%s", word);                 
                replace(cursor,word);
                //printf("\n"); print_text(beg_txt); printf("\n\n");
                break;

            case 'a': //insert a word after the word the cursor points at;
                scanf("%s", word);
                insert_after(cursor,end_txt, word);
                //printf("\n"); print_text(beg_txt); printf("\n\n");
                break;

            case 'f': //look up for a word in the list and return it index;
                scanf("%s",word); 
                if(search(beg_txt,cursor,word) != -1)
                    printf("%d\n",search(beg_txt,cursor,word));
                break;
        }
    }

    fclose(txt_file);
    return 0;

}