#include "text_editor.h"

int main(){

    FILE *txt_file;
    char file_name[100];
    char txt[100000];
    char aux[1000];
    int num_lines = 0;
    
    
    scanf("%s",file_name);    
    strcat(file_name,".ext");
    txt_file = fopen(file_name,"r");

    while(!feof(txt_file)){
        fgets(aux,100000,txt_file);
        strcat(txt, aux);
    }

    node** txt_ls = split_text(txt);
    
    print_number(txt_ls);

    return 0;

}