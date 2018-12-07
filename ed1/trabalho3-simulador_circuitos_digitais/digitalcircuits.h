#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define ok 1
#define error 0
#define debug printf("\n teste \n")


typedef struct node
{
	char tag[4];
	int bit;
	struct node* rgt;
	struct node* lft;
}Node;

typedef Node* Gate;

Node* SetExit();
char** Split(char* str, char* divider);
int InsertGates0(Node** root, char** gateTags);
int InsertGates1(Node** root, char** gateTags, int* i);
int RunSimulation(Node** root, int* input, int* i);
int BitOperation(char operation, int bit1, int bit2);
void PrintCircuit(Node** root);
void DestroyCircuit(Node** root);
