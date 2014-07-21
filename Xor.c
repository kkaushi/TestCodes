#include <stdio.h>

typedef struct nodeStruct
{
	int val;
	struct nodeStruct * next;
}node;

node *start,*end;


void printArray(int * arr,int length)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

node * createNewNode(int val)
{
	node * newNode=(node *) malloc(sizeof(node));
	newNode->val=val;
	newNode->next=NULL;
	return newNode;
}
void main()
{
	int arr[5]={1,2,3,4,5};
	printArray(arr,5);
}
