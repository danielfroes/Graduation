#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    while(strcmp(a,"0") != 0){
        scanf("%s",a);
        if(a[0] < '5')
            printf("ordem de grandeza: %ld\n",strlen(a)-1);
        else
            printf("ordem de grandeza: %ld\n",strlen(a));
    }   
    return 0;
}