#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
	char data;
	struct listNode *nextPtr;
}Node;

void printList(Node *headPtr);
int main(void)
{
	int val;
	int count = 5;

	Node *head = (Node*)malloc(sizeof(Node));

	printf("Insert first node number: ");
	scanf_s("%d", &val);

	head->data = val;
	head->nextPtr = NULL;

	Node *currentNode = head;

	for(int i=0; i<count; i++)
	{
		currentNode->nextPtr = (Node*)malloc(sizeof(Node));
		currentNode = currentNode->nextPtr;
		
		printf("Insert %d node number: ", i+1);
		scanf_s("%d", &val);

		currentNode->data = val;
		currentNode->nextPtr = NULL;
	}
	
	printList(head);

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