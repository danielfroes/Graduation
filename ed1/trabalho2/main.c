#include "text_editor.h"

int main(){
    FILE *file;
    char file_name[100];
    char text[100000];
    char aux[1000];
    int num_lines = 0;
    scanf("%s",file_name);    
    strcat(file_name,".ext");
    file = fopen(file_name,"r");
    while(fgets(aux,100000,file) != NULL){
        num_lines++;
    }
    fclose(file);
    file = fopen(file_name,"r");
    printf("%d\n",num_lines);
    for (int i = 0; i< num_lines; i++){
        fgets(aux,100000,file);
        strcat(text,aux);
        
    }
    printf("%s",text);
    
    fclose(file);
    return 0;
}