#include "sort.h"

int main(){
    int a_len = 100000;
    int step = 0;
    int range = 100000000;

    /*
    printf("tamanho: ");
    scanf("%d",&a_len);
    printf("passo: ");
    scanf("%d", &step);
    printf("range: ");
    scanf("%d",&range);
    */

    int a[a_len];

    init(a, a_len, step, range);

    quick_sort( a, 0, a_len - 1);

    print_array(a, a_len);
    
    return 0;
}