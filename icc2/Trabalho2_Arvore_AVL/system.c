#include "system.h"

void splashScreen()
{
	//Telinha
}

void cleanScreen()
{
	printf("\e[H\e[2J");
}

void cleanBuffer()
{
	while (getchar() != '\n')
		;
}

void pressEnter()
{
	printf("\n\n        Pressione ENTER para prosseguir\n\n");
	char c = getchar();
	while (c != '\n')
		c = getchar();
}

void MenuSobre()
{
	cleanScreen();
	printf("              Implentacao de Arvores Binarias\n");
	printf("                       Sobre o projeto       \n\n\n\n\n\n");
	printf("      Programa para criacao e manipulacao de arvores binarias\n\n");
	printf(" Projeto da disciplina de Introducao a Ciencia da Computacao II\n\n");
	printf("                 Universidade de Sao Paulo\n\n\n");
	printf("\n\nPressione ENTER para seguir para as informacoes dos autores\n\n");
	char c = getchar();
	while (c != '\n')
		c = getchar();

	cleanScreen();
	printf("                     Criado por:\n");
	printf("                Daniel da Rocha Froes:\n");
	printf("                  danielfroes@usp.br\n");
	printf("                github.com/danielfroes\n\n");
	printf("                         e\n\n");
	printf("              Gabriel Santos Nicolau:\n");
	printf("            gabriel.nicolau97@hotmail.com\n");
	printf("                 github.com/7Nic\n\n");
}

int menu()
{
	int inputUser;
	printf("                       Menu principal\n");
	printf("\n");
	printf("1 - Inserir elemento                   2 - Remover elemento\n");
	printf("3 - Buscar elemento                    4 - Imprimir a arvore\n");
	printf("5 - Sobre                              6 - Sair do programa \n");
	printf("\n");
	printf("Digite sua escolha:");
	scanf("%d", &inputUser);
	cleanBuffer();
	return inputUser;
}
