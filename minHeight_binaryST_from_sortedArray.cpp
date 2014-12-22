#include<stdio.h>
#include<stdlib.h>

//bst node
typedef struct bstnode
{
	int key;
	struct bstnode * parent;
	struct bstnode * left_child;
	struct bstnode * right_child;
}node;

//global root pointer
node * root;

//create new node
node *create_new_node(int data)
{
	node * ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->key=data;
	ptr->left_child=NULL;
	ptr->right_child=NULL;
	ptr->parent=NULL;
	return ptr;
}


node * createBST(int * arr, int l, int r)
{
	int middle = l+(r-l+1)/2;
	node * n;
	if(r==l||l>r)
	{
		n=create_new_node(arr[r]);		
	}	
	else
	{
		n=create_new_node(arr[middle]);
		if(middle>l)//IMPORTANT : TO AVOID DUPLICATION OF EXISTING NODES
			n->left_child=createBST(arr,l,middle-1);
		if(middle<r)//IMPORTANT : TO AVOID DUPLICATION OF EXISTING NODES
			n->right_child=createBST(arr,middle+1,r);
	}
	return n;
}

void inorder(node * ptr)
{
	if(ptr!=NULL)
	{	
		
		inorder(ptr->left_child);
		//prntf("%d\t%s\t%s\n",ptr->key,ptr->word,ptr->meaning);
		printf("%d\n",ptr->key);
		//puts(ptr->word);
		//puts(ptr->meaning);
		inorder(ptr->right_child);
	
	}
	else
		return;
}

int main()
{
	int arr[]={1,22,23,24,55,66};
	int len=sizeof(arr)/sizeof(int);
	root=createBST(arr, 0,len-1);

	//Inorder traversal of tree now
	inorder(root);

	return 0;
}

