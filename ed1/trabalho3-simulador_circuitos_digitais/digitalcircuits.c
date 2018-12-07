#include "digitalcircuits.h"

Node* SetExit() // cria a arvore e coloca o primeiro nó como a saida do sinal
{
    Node* gate = (Node*)calloc(1,sizeof(Node));
    gate->rgt = NULL;
    gate->lft = NULL;
    strcpy(gate->tag, "S00");
    return gate;
}

char** Split(char* str, char*  divider ) //pega uma string e divide em um vetor de substring, de acordo com o delimitador
{
    char* token, ** matrix;

    token =  strtok(str, divider); // pega a substring ate o primeiro espaço
    matrix = (char**) calloc (1000, sizeof(char*));    

    int i = 0;
    while(token != NULL) //continua o processo de passar pela string,
    {
        matrix[i] = (char*) calloc (3, sizeof(char)); 
        strcpy(matrix[i], token); //
        token = strtok(NULL, divider);
        i++;
    }

    return matrix;
}

int InsertGates0(Node** atual, char** gateTags) //inseri as portas um por um
{
    if((*atual) == NULL)
        return true;


    if(strcmp((*atual)->tag,"S00") == 0 && (*atual)->lft == NULL) //se apenas tiver o nó de saída insere o primeiro nó
    {
        (*atual)->lft = (Node*)calloc(1, sizeof(Node)); 
        strcpy((*atual)->lft->tag,gateTags[0]);

    }

    if(strcmp((*atual)->tag, gateTags[0]) == 0) //se achou o nó pai, insere os dois nós filhos
    {
        if(gateTags[0][0] == 'N') // caso a porta pai seja not, insere somente o filho da esquerda
        {
            (*atual)->lft = (Node*)calloc(1, sizeof(Node));
            strcpy((*atual)->lft->tag, gateTags[1]);

        }
        else// insere os filhos;
        {
            (*atual)->lft = (Node*)calloc(1, sizeof(Node));
            strcpy((*atual)->lft->tag, gateTags[1]);

            (*atual)->rgt = (Node*)calloc(1, sizeof(Node));
            strcpy((*atual)->rgt->tag,gateTags[2]);
        }       
    }

    
    InsertGates0(&(*atual)->lft, gateTags); //vai para esquerda 
    InsertGates0(&(*atual)->rgt, gateTags); //vai para direita
}


int InsertGates1 (Node** atual, char** gateTags, int* i) //insere os nós todos de uma vez
{
    if((*atual) == NULL) //se o nó é nulo, insere um nó
    {
        (*atual) = (Node*) calloc(1, sizeof(Node));
        strcpy((*atual)->tag, gateTags[*i]);
        (*i)++; //incrementa o index, indo para o proxima tag no array
        (*atual)->lft = NULL;
        (*atual)->rgt = NULL;
        
        if((*atual)->tag[0] == 'E') //condição de parada da recursão acontece se o nó inserido for uma entrada, 
            return true;
    }

    InsertGates1(&(*atual)->lft, gateTags, i); //vai para esquerda;
    
    if((*atual)->rgt == NULL && (*atual)->tag[0] != 'N' && (*atual)->tag[0] != 'S') //so ir para direita se respeitar tais condições
        InsertGates1(&(*atual)->rgt, gateTags, i);
}




void PrintCircuit(Node** root) // Imprime os nós da árvore (as informações contidas nele) da menor chave para maior;
{
    
    if (root == NULL) //condição para o desimpilhamento da recursão
    {
        return;
    }

    if (*root != NULL)
    {
        printf("%s e seu bit %d\n",(*root)->tag, (*root)->bit);
        PrintCircuit(&((*root)->lft));
        PrintCircuit(&((*root)->rgt));
    }

}


int RunSimulation(Node** atual, int* input, int* i) // roda a simulação do circuito, setando as entradas de acordo com o input do usuario
{   
    if((*atual) == NULL) //condição de parada caso o nó atual é nulo
        return -1;
      
    if((*atual)->tag[0] ==  'E') // condição de parada caso o nó seja a entrada
    {
        (*atual)->bit = input[*i]; //seta o bit da entrada com o input corresponde
        (*i)++; // vai para o proximo input
        return (*atual)->bit;
    }

    RunSimulation(&(*atual)->lft, input, i); //vai para esquerda
    RunSimulation(&(*atual)->rgt, input, i); //vai para direita

    if((*atual)->tag[0] == 'N' || (*atual)->tag[0] == 'S') // para os casos da entrada for o not ou saida, eles so terão um filho, o outro é nulo, por isso somente passando o esquerdo;
        (*atual)->bit = BitOperation((*atual)->tag[0], (*atual)->lft->bit, -1); //faz a operação com os bit filho
    else
        (*atual)->bit = BitOperation((*atual)->tag[0], (*atual)->lft->bit, (*atual)->rgt->bit); // faz a operação com os bits filhos

    return (*atual)->bit; //retorna o valor do bit do nó atual, assim, quando estiver o nó da saída, retorna o bit resultante da simulação 
}

int BitOperation(char op, int bit1, int bit2) //um selecionador das operações que cada porta pode fazer dependendo da tag
{
    int res;
    switch (op)
    {
        case 'S': //saida 
            res = bit1;
        break;
         
        case 'A': //and
            res = bit1 & bit2;
        break;

        case 'O': //or
            res = bit1 | bit2;
        break;

        case 'D': //nand
            res = !(bit1 & bit2);
        break;

        case 'R': //nor
            res = !(bit1 | bit2);
        break;

        case 'X': //xor
            res = bit1 ^ bit2;
        break;
         
        case 'N': //not
            res = !bit1;
        break;
    }
    
    return res; // retorna o resultado da operação selecionada.
}