#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
	char data;
	struct listNode *nextPtr;
}Node;

void insertNode(Node *headPtr, int newVal);
void deleteNode(Node *headPtr, int delVal);
void printList(Node *headPtr);
int main(void)
{
	int val, num;
	int count = 5;

	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->nextPtr = NULL;

	printf("Insert  number of nodes: ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) 
	{
		printf("Insert  node number: ");
		scanf_s("%d", &val);
		insertNode(head, val);
		printList(head); //print from head
	}
	
	printf("Insert delete number: ");
	scanf_s("%d", &val);

	deleteNode(head, val);
	printList(head); //print from head
	system("pause");
	return 0;
}
void printList(Node *headPtr)
{
	Node *currentNode = headPtr;
	while (currentNode != NULL)
	{
		printf("%d -> ", currentNode->data);
		currentNode = currentNode->nextPtr;
	}
}
void deleteNode(Node *headPtr, int delVal)
{
	Node *currentNode;
	Node *previousNode;

	currentNode = headPtr;
	previousNode = NULL;
	if (headPtr == NULL)
	{
		printf("First Node not found");
	}

	if (delVal == headPtr->data) //Delete if first node is
	{
		headPtr = headPtr->nextPtr;
		free(currentNode);
		currentNode = headPtr;
	}

	while (currentNode != NULL && delVal != currentNode->data)
	{
		previousNode = currentNode;
		currentNode = currentNode->nextPtr;
	}

	if (currentNode == NULL)
	{
		printf("Value not found");
	}
	else
	{
		previousNode->nextPtr = currentNode->nextPtr;
		free(currentNode);
	}

}
void insertNode(Node *headPtr, int newVal)
{
	Node *currentNode;
	Node *newNode = (Node*)malloc(sizeof(Node)); //malloc return void *, so we need to cast type to Node *

	currentNode = headPtr;

	newNode->data = newVal;
	newNode->nextPtr = NULL;

	while (currentNode->nextPtr != NULL) 
	{
		currentNode = currentNode->nextPtr;
	}
	currentNode->nextPtr = newNode;
	currentNode = currentNode->nextPtr;
	
}