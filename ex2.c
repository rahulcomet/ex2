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

void Breadth_First_Traversal(FILE* outptr, TNode* node){
    // fprintf(outptr, “%d\n”, node->label);
}

void Depth_First_Traversal(FILE* outptr, TNode* node){
    // fprintf(outptr, “%d\n”, node->label);
}
