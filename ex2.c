#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
	int label;
	struct TNode* left;
	struct TNode* right;
}TNode;

typedef struct Queue{
	struct Queue* next;
	TNode *node;
}Queue;

typedef struct QHeader{
	Queue *front;
	Queue *rear;
}QHeader;

void Enqueue(QHeader * header, TNode* node){
	Queue* toInsert = (Queue *)malloc(sizeof(Queue));
	toInsert->node = node;
	toInsert->next = NULL;
	if(header->rear == NULL){
		header->rear = header->front = toInsert;
	}
	else{
		header->rear->next = toInsert;
		header->rear = toInsert;
	
}

TNode* Dequeue(QHeader *header){
	if(header->front == NULL)
		return NULL;
	Queue *toDeq = header->front;
	header->front = header->front->next;
	if(header->front == NULL)
		header->rear = NULL;
	TNode* toReturn = toDeq ->node;
	free(toDeq);
	return toReturn;
}

void Breadth_First_Traversal(FILE* outptr, TNode* node){		//printing a node, queuing its child nodes and then looping through
	QHeader *head = (QHeader *)malloc(sizeof (QHeader));
	Tnode *tnode = node;
	while (tnode != NULL)
	{
		 fprintf(outptr, “%d\n”, tnode->label);
		 if(tnode ->right != NULL)
		 {
			 Enqueue(head, tnode->right);
		 } 
		 if(tnode ->left != NULL)
		 {
			 Enqueue(head, tnode->left);
		 }
		 tnode = Dequeue(head);
	}
}

void Depth_First_Traversal(FILE* outptr, TNode* node){			//using the concept of postorder traversal but recurring through right child before left child
    if(node == NULL)
	{
		return;
	}
	Depth_First_Traversal(node->right);
	Depth_First_Traversal(node->left);
	fprintf(outptr, “%d\n”, node->label);
}
