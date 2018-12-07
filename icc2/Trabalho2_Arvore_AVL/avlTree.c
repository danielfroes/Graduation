#include "avlTree.h"

//funções auxiliares

int NodeHeight(NodePtr node)
/*
#Retorna o valor da altura de determinado nó da árvore.
#Caso o nó aponte para nulo, o valor retornado é -1,
 sendo essa uma decisão de projeto para facilitar o cálculo do fator de balanceamento.
*/
{
    if (node == NULL)
        return -1;
    else
        return node->height;
}

int Greater(int nodeA, int nodeB)
/*
#Compara os números dados e retorna o maior;
*/
{
    if (nodeA > nodeB)
        return nodeA;
    else
        return nodeB;
}

int BalanceFactor(NodePtr node)
/*
#Calcula o fator de balanceamento de determinado nó da árvore.
#O fator de balancemento pode ser definido pela diferença entre 
 a altura do nó filho esquerdo com o nó filho direito;
*/
{
    return abs(NodeHeight(node->lft) - NodeHeight(node->rgt));
}

void LftRotation(NodePtr *oldRoot)
/*
#Faz a rotação no sentido esquerdo (anti horário)
#Rotação é uma manobra com os nós da árvores responsável por manter a árvore balanceada
 (fator de balancemanto em cada nó menor do que 2);
*/
{
    Node *newRoot;
    newRoot = (*oldRoot)->rgt;
    (*oldRoot)->rgt = newRoot->lft;
    newRoot->lft = (*oldRoot);
    (*oldRoot)->height = Greater(NodeHeight((*oldRoot)->lft), NodeHeight((*oldRoot)->rgt)) + 1;
    newRoot->height = Greater(NodeHeight(newRoot->rgt), (*oldRoot)->height) + 1;
    (*oldRoot) = newRoot;
}

void RgtRotation(NodePtr *oldRoot)
/*
#Faz a rotação no sentido direito (horário)
#Rotação é uma manobra com os nós da árvores responsável por manter a árvore balanceada
 (fator de balancemanto em cada nó menor do que 2);
*/
{
    Node *newRoot;
    newRoot = (*oldRoot)->lft;
    (*oldRoot)->lft = newRoot->rgt;
    newRoot->rgt = *oldRoot;
    (*oldRoot)->height = Greater(NodeHeight((*oldRoot)->lft), NodeHeight((*oldRoot)->rgt)) + 1;
    newRoot->height = Greater(NodeHeight(newRoot->lft), (*oldRoot)->height) + 1;
    *oldRoot = newRoot;
}

void PrintTree(NodePtr *root)
/*
Imprime os nós da árvore (as informações contidas nele) da menor chave para maior;
*/
{

    if (root == NULL) //condição para o desimpilhamento da recursão
    {
        return;
    }

    if (*root != NULL)
    {
        PrintTree(&((*root)->lft));                                                                                    // vai para o nó mais a esquerda, ou seja, a menor chave;
        printf("chave:%d, valor:%d, fator de balanceamento:%d\n", (*root)->key, (*root)->value, BalanceFactor(*root)); //imprime as informações
        PrintTree(&((*root)->rgt));                                                                                    // vai percorrendo o restantes dos nós a direita a partir do desimpilhamento da primeira pilha da recursão;
    }
}

void SearchNode(NodePtr current, int key)
/*
#procura por um nó com uma determinada árvore,
 imprime as informações contidas nele e retorna um ponteiro para o mesmo;
#Como a árvore está ordenada, a busca tem complexidade de log n;
*/
{
    if (current == NULL) // se a chave procurada nao estiver na árvore
    {
        printf("Chave nao encontrada na busca\n");
        return;
    }
    if (key == current->key) // se o nó atual conter a chave procurada
    {
        printf("O valor associado a chave e: %d, e sua altura eh : %d\n", current->key, current->height);
        return;
    }
    else if (key > current->key) //caso a chave seja maior do que a chave do nó atual, vai para o nó da direita;
    {
        SearchNode(current->rgt, key);
    }
    else //caso a chave seja menor do que a chave do nó atual, vai para o nó da direita;
    {
        SearchNode(current->lft, key);
    }
}

void InsertNodeAVL(NodePtr *current, int key, int value)
/*
#Insere um nó na árvore de maneira ordenada.
#A função a seguir é feita já implementando o algoritmo de balanceamento AVL,
 assim, ele ao inserir o novo nó, já balancea alguma possível subárvore desbalanceada pela inserção.
*/
{
    if (*current == NULL) //se estiver na folha determinada, insere o nó
    {
        NodePtr newNode = (NodePtr)calloc(1, sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->height = 0;
        newNode->rgt = NULL;
        newNode->lft = NULL;
        *current = newNode;
        return;
    }
    else if (key == (*current)->key) // se já existe um nó com a chave, atualiza o seu valor;
    {
        (*current)->value = value;
        return;
    }
    else if (key > (*current)->key) //caso a chave seja maior do que a do nó atual, vai para direita
    {
        InsertNodeAVL(&((*current)->rgt), key, value);
        if (BalanceFactor((*current)) >= 2) // se a subarvore está desbalanceada, aplicar AVL
        {
            if ((*current)->rgt->key < key)
            {
                LftRotation(current);
            }
            else
            {
                RgtRotation(&((*current)->rgt));
                LftRotation(current);
            }
        }
    }
    else if (key < (*current)->key) //caso chave seja menor que a do nó atual, vai para esquerda
    {
        InsertNodeAVL(&((*current)->lft), key, value);
        if (BalanceFactor((*current)) >= 2) // se a subarvore está desbalanceada, aplicar AVL
        {
            if ((*current)->lft->key > key)
            {
                RgtRotation(current);
            }
            else
            {
                LftRotation(&((*current)->lft));
                RgtRotation(current);
            }
        }
    }

    (*current)->height = Greater(NodeHeight((*current)->lft), NodeHeight((*current)->rgt)) + 1; //atualiza a altura dos nós afetados pela inserção
}

void RemoveNodeAVL(NodePtr *current, int key)
/*
#Remove um nó com determinada chave da árvore, balanceando os nós afetado pela remoção com o algorítmo de balancemento AVL
*/
{
    //procura pelo nó na arvore

    if (*current == NULL) //chave não existe na árvore
    {
        printf("chave nao existe!!\n");
        return;
    }
    if (key < (*current)->key) //caso chave seja menor que a do nó atual, vai para esquerda
    {
        RemoveNodeAVL(&(*current)->lft, key);

        if (BalanceFactor(*current) >= 2) // se a subarvore está desbalanceada, aplicar AVL
        {
            if (NodeHeight((*current)->rgt->lft) <= NodeHeight((*current)->rgt->rgt))
            {
                LftRotation(current);
            }
            else
            {
                RgtRotation(&((*current)->rgt));
                LftRotation(current);
            }
        }
    }

    if (key > (*current)->key) //caso a chave seja maior do que a do nó atual, vai para direita
    {
        RemoveNodeAVL(&(*current)->rgt, key);
        if (BalanceFactor(*current) >= 2) // se a subarvore está desbalanceada, aplicar AVL
        {
            if (NodeHeight((*current)->lft->rgt) <= NodeHeight((*current)->lft->lft))
            {
                RgtRotation(current);
            }
            else
            {
                LftRotation(&((*current)->lft));
                RgtRotation(current);
            }
        }
    }

    if ((*current)->key == key) //se o nó conter a chave procurada, remover esse nó;
    {
        if (((*current)->lft == NULL || (*current)->rgt == NULL)) //algoritmo para se o nó tem um ou nenhum filho
        {
            NodePtr oldNode = (*current);
            if ((*current)->lft != NULL)
                *current = (*current)->lft;
            else
                *current = (*current)->rgt;
            free(oldNode);
        }
        else //algoritmo para se o nó tem 2 filhos
        {
            NodePtr temp = (*current)->rgt;
            while (temp->lft != NULL)
                temp = temp->lft;

            (*current)->key = temp->key;

            RemoveNodeAVL(&(*current)->rgt, (*current)->key);

            if (BalanceFactor(*current) >= 2)
            {
                if (NodeHeight((*current)->lft->rgt) <= NodeHeight((*current)->lft->lft))
                {
                    LftRotation(current);
                }
                else
                {
                    RgtRotation(&((*current)->rgt));
                    LftRotation(current);
                }
            }
        }
        if (*current != NULL)
            (*current)->height = Greater(NodeHeight((*current)->lft), NodeHeight((*current)->rgt)) + 1; //atualiza a altura;
        return;
    }

    (*current)->height = Greater(NodeHeight((*current)->lft), NodeHeight((*current)->rgt)) + 1;
}
