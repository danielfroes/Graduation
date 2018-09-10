#include "bin_calc.h"

int main(){

    int quantity_of_numbers; 

    bin num; 
    bin sum;

    char number[1000]; //the number will initially be read as a string
    int number_len; //the lenght of the number

    scanf("%d",&quantity_of_numbers);

    for (int i = 0 ; i < quantity_of_numbers ; i++){ //read the specified quantity of numbers and sum them all
        scanf("%d",&number_len);
        scanf("%s",number);

        num = create_number(number,number_len); // tranform the array into a list 

        if(i == 0){ //in the first iteration sum stores number;
            sum = num;  
        } 
        else{ //in the other ones sum receives the last number and the new one
            sum = add(num,sum);
        }
    }

    print_number(sum); // print the number

    free_number(sum); //free them from the memory
    free_number(num);
    
    return 0;

}