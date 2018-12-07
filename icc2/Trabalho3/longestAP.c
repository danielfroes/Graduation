#include <stdlib.h>
#include <stdio.h>

int *constroiPA(int r, int APlen, int firstElem);
int achaParametrosPA(int a[], int n, int *r, int *firstElem);
void quick_sort(int *a, int left, int right);

int main(int argc, char const *argv[]) //recebe os parâmetros na linha de execução
{
    int len = argc - 1;  // tamanho do array de valores
    int *array = calloc(len, sizeof(int));
    int r = 0;
    int firstElem = 0;

    for (int i = 0; i < len; i++)//pega o input que esta em formato de string e coloca em um vetor de inteiros
        array[i] = atoi(argv[i + 1]); 

    quick_sort(array, 0, len - 1); // ordena o vetor

    int APlen = achaParametrosPA(array, argc, &r, &firstElem); //acha os parâmetros da PA

    int *longestAP = constroiPA(r, APlen, firstElem); //constroi a PA

    printf("resultado: ");
    for (int i = 0; i < APlen; i++) // printa o resultado
        printf("%d ", longestAP[i]);
    printf("\n");

    return 0;
}

int *constroiPA(int r, int APlen, int firstElem)
{
    int *array = (int *)calloc(APlen, sizeof(int)); 
    
    for (int i = 0; i < APlen; i++) //constroi a PA a partir dos parâmetros
        array[i] = firstElem + r * i;

    return array;
}

int achaParametrosPA(int a[], int n, int *r, int *firstElem)
{
    int i, j, k;
    int TabelaRes[n][n]; //tabela de resultados
    int PAtam = 2;

    for (i = 0; i < n; i++) //na ultima coluna, sempre vai ser dois, j é o maior elemento
        TabelaRes[i][n - 1] = 2;

    for (j = n - 2; j >= 1; j--) // loop de n-2 ate 1, variando j
    {   
        /*seta i e k como vizinhos de j*/
        i = j - 1; 
        k = j + 1;

        while (i >= 0 && k < n) //ate i ou k ultrapassar o vetor
        {
            if (2 * a[j] > a[i] + a[k]) // a soma foi muito pequena, portanto para aumentar a soma, incrementar o k;
            {
                k++;
            }
            else if (2 * a[j] < a[i] + a[k]) // a soma foi muito grande, portanto, para diminuir a soma, decrementar i;
            {
                TabelaRes[i][j] = 2; // preenchimento da tabela depende de i, portanto, antes de muda-lo preencher a tabela;
                i--;
            }
            else
            {
                TabelaRes[i][j] = TabelaRes[j][k] + 1; // busca o tamanho da possível PA anterior e atualiza seu tamanho, visto que foi achado mais um elemento;
                if (PAtam < TabelaRes[i][j]) //se este foi o maior tamanho de PA até agora, setar os parâmetros que serão retornados
                {
                    PAtam = TabelaRes[i][j];
                    *firstElem = a[i];
                    *r = a[j] - a[i];
                }
                i--;
                k++;
            }
        }
        while (i >= 0) //preenche os espaços nao preenchidos na Tabela de resultados
        {
            TabelaRes[i][j] = 2;
            i--;
        }
    }
    return PAtam; 
}

void quick_sort(int *a, int left, int right)
{
    /*
    Quick sort
        #Descrição
            Divide o vetor em dois a partir de um pivo, do lado esquerdo
            do pivo são colocados os valores menores a ele e do direito
            são colocados os maiores. recursivamente, repete-se essa etapa
            para ambos os subvetores;
        #Complexidade
            Tempo:
                worst: O(n²)(raro)
                best: best: Ω(nlog(n))
    */
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < x && i < right)
            i++;
        while (a[j] > x && j > left)
            j--;
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
        quick_sort(a, left, j);
    if (i < right)
        quick_sort(a, i, right);
}
