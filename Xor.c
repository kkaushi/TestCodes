#include <stdio.h>

typedef struct nodeStruct
{
	int val;
	struct nodeStruct * next;
}node;

node *start;
int arr[5]={1,2,3,4,5};

void printArray(int * arr,int length)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

//xor calculates xor of two nodes a and b
node *xor(node *left,node *right)
{
	if(left != NULL && right !=NULL)
	{
		return (node*)((long long)(left)^(long long)(right));
	}
	else if(left == NULL && right != NULL)
	{
		return right;
	}
	else 
	{
		return left;
	}
}

node * createNewNode(int val)
{
	node * newNode=(node *) malloc(sizeof(node));
	newNode->val=val;
	newNode->next=NULL;
	return newNode;
}
void insertNewNode(node* ptr, node* ptrNext, node* ptrPrev)
{
	if(start==NULL)
	{
		//printf("Here: Inside insertNewNode first if\n");
		start=ptr;
	}
	else
	{
		//printf("Here: Inside insertNewNode first else\n");
		if(ptrPrev !=NULL)
		{
			ptrPrev->next=xor(xor(ptrPrev->next,ptrNext),ptr);
		}
		if(ptrNext != NULL)
		{
			ptrNext->next=xor(xor(ptrNext->next,ptrPrev),ptr);
		}
	}
	ptr->next=xor(ptrNext,ptrPrev);
}

void traverseList()
{
	node * temp = start;
	node * prev = NULL;
	node * next = NULL;
	while (temp->next != prev)
	{
		printf("-->%d\t",temp->val);
		next=xor(prev,temp->next);
		prev=temp;	
		temp=next;
	}
	printf("-->%d\n",temp->val);
}

void insert5nodes()
{
	node* allNodes[5];
	allNodes[0]=createNewNode(arr[0]);
	allNodes[1]=createNewNode(arr[1]);
	allNodes[2]=createNewNode(arr[2]);
	allNodes[3]=createNewNode(arr[3]);
	allNodes[4]=createNewNode(arr[4]);
	insertNewNode(allNodes[0],NULL,NULL);
	insertNewNode(allNodes[1],NULL,start);
	insertNewNode(allNodes[2],NULL,allNodes[1]);
	insertNewNode(allNodes[3],NULL,allNodes[2]);
	insertNewNode(allNodes[4],NULL,allNodes[3]);
}

void main()
{
	printArray(arr,5);
	insert5nodes();	
	traverseList();
	//printf("%d\t", start->val);
	//printf("%d\t",start->next->val);
}
