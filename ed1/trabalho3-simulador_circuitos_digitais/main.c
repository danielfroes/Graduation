#include "digitalcircuits.h"

int main()
{
    Gate root = SetExit(); // cria a árvore e insere o primeiro nó de saída na raiz;

    int numOp,nmbEntries = 0, breakLoop = false, zero = 0, nmbInputs;
    char option, opStr[1000], ** opArray;
        
    while(!breakLoop)
    {
        scanf("%c", &option); // seleciona o tipo de inserção

        if(option == '0')
        {
            scanf("%d", &numOp);  // lê numeros de comandos a serem inseridos pelo usuario
            for(int i = 0; i < numOp; i++)
            {
                scanf(" %[^\n]s", opStr); // lê as tags em uma só string
                
                //faz um vetor em que cada elemento é uma das tags;
                opArray = Split(opStr, " "); 

                //faz o calculo do numero de entradas do circuito;
                if(opArray[1][0] == 'E')
                    nmbEntries++;
                if(opArray[0][0] != 'N') // se a porta é not, o filho a direita vai ser null, logo, é desconsiderado a terceira tag;
                {
                    if(opArray[2][0] == 'E')
                        nmbEntries++;
                }

                InsertGates0(&root, opArray); // inserção do tipo 0;
            }
            breakLoop = true;
        }
        else if(option == '1')
        {              

            scanf(" %[^\n]s", opStr); //lê todas as tags em uma unica string;

            opArray = Split(opStr, " "); //cria um vetor de tags;
         
            for(int j = 0; opArray[j] != NULL; j++) // calcula o numero de entradas
            {
                if(opArray[j][0] == 'E')
                    nmbEntries++;
            }

            InsertGates1(&root, opArray, &zero); //inserção do tipo 1, a variavel zero controla o index do opArray, assim, inicializando-se com 0;

            zero = 0; //seta o valor de zero;

            breakLoop = true;
        }
        else
        {
            printf("opcao invalida\n");
        }
    }

    scanf("%d", &nmbInputs); //le a quantidade de sinais de inputs que serão lidos para a simulação

    int input[nmbEntries], results[nmbInputs];

    
    for(int i = 0; i < nmbInputs; i++) 
    {
        for(int j = 0; j < nmbEntries; j++) // lê um inputs, de acordo com a quantidade de entradas no circuito
            scanf("%d", &input[j]);
        
        results[i] = RunSimulation(&root, input, &zero); // roda a simulação e guarda o resultado
        zero = 0; // seta o valor de zero
    }

    for(int i = 0; i < nmbInputs; i++) // printa os resultados
        printf("%d\n", results[i]);

    return 0;
}
