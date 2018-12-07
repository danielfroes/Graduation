#include "avlTree.h"

int main(){
    int chave, valor;
    int loop = TRUE;
    NodePtr root = NULL; //Inicia a raiz como root

    while(loop)
    {
        cleanScreen();
        int inputUser = menu();
        switch(inputUser)
        {
            case 1:
                printf("Digite a chave:");
                scanf("%d", &chave);
                cleanBuffer();
                printf("Digite o valor:");
                scanf("%d", &valor);
                InsertNodeAVL(&root, chave, valor);
            break;
        
            case 2:
                printf("Digite a chave:");
                scanf("%d", &chave);
                cleanBuffer();
                RemoveNodeAVL(&root, chave);
            break;
        
            case 3:
                printf("Digite a chave:");
                scanf("%d", &chave);
                cleanBuffer();
                SearchNode(root, chave);
                
            break;
            
            case 4:
                PrintTree(&root);
                cleanBuffer();
            break;

            case 5:
                MenuSobre();
            break;

            case 6:
                exit(0);
            default:
                printf("Opcao inexistente");
            break;
        
        }
        pressEnter();
    }

}
