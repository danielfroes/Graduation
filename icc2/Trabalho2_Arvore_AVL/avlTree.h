#include "system.h"


struct Node {
   int key;
   int value;
   int height;
   struct Node *lft;
   struct Node *rgt;
};

typedef struct Node Node;
typedef struct Node* NodePtr;

void InsertNodeAVL(Node** root, int key, int value);
void RemoveNodeAVL(Node** root, int key);
void SearchNode(Node* root, int key);
int NodeHeight(Node* no);
int BalanceFactor(Node* node);
int Greater(int nodeA, int nodeB);
void LftRotation (Node** node);
void RgtRotation (Node** node);
void PrintTree(Node** root);