#include "text_editor.h"


int main(){
    //declaration of the variables;
    FILE *txt_file;
    char file_name[100],txt[100000], aux[1000], word[30], option;
    int num_lines = 0, terminate = 1, n;
    node** beg_txt; // first node of the list
    node** cursor = (node**)calloc(1,sizeof(node*)); //cursor
    node** end_txt = (node**)calloc(1,sizeof(node*)); //last node of the list
    
    //treating the file name and opening it 
    scanf("%s",file_name);    
    strcat(file_name,".ext");
    txt_file = fopen(file_name,"r");
    
    //getting all the text of the file;
    while(!feof(txt_file)){
        fgets(aux,1000,txt_file);
        strcat(txt, aux);
    }
  
    beg_txt = split_text(txt, end_txt);//creating the list and initializing the first node;
    *cursor = *beg_txt; //initializing the cursor
    
    while(!terminate){   
        scanf("%c",&option); //getting the option

        switch(option){
            case 's' : //print the text and terminate the program
                print_text(beg_txt);
                terminate = 0;
                break;

            case 'n' : //advances the cursor to the next word
                move_cursor_to(cursor, 1);
                break;
            
            case 'p' : // advances the cursor to the previous word
                move_cursor_to(cursor, -1);
                break;
            
            case 'b' : // put the cursor to the beggining of the text
                move_cursor_to_begin(cursor, beg_txt);
                break;

            case 'e' : // put the cursor to the end of the text
                move_cursor_to_end(cursor, end_txt);
                break;
            
            case 'd' :  // remove the word that the cursor points
                remove_word(cursor,beg_txt,end_txt);
                break;

            case 'g' : //move the cursor n times
                scanf("%d", &n);
                move_cursor_to(cursor, n);
                break;
            
            case 'i' : //insert a word before the word the cursor is pointing
                scanf("%s", word);
                insert_before(cursor,beg_txt,word);
                break;

            case 'r': //replace the word that the cursor is pointing to;
                scanf("%s", word);                 
                replace(cursor,word);
                break;

            case 'a': //insert a word after the word the cursor points at;
                scanf("%s", word);
                insert_after(cursor,end_txt, word);
                break;

            case 'f': //look up for a word in the list and return it index;
                scanf("%s",word); 
                if(search(beg_txt,cursor,word) != -1)
                    printf("%d\n",search(beg_txt,cursor,word));
                break;
        }
    }

    fclose(txt_file); //closing the file;
    return 0;

}
