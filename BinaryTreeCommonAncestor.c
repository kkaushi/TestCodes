#include<stdio.h>
/* How to find a common ancestor of two nodes in a Binary (not BST) tree */

//tree node
struct btnode
{
	int val;
	struct btnode * l;
	struct btnode * r;
}*root;

//tree node initialization
int initNode(int v)
{
	struct btnode *temp=
	(struct btnode *) malloc(sizeof(struct btnode));
	
	temp->val=v;
	temp->l=NULL;
	temp->r=NULL;
	return temp;
}

//is node n present in tree/subtree rooted at node tree
int IsNodeInTree(struct btnode* tree, struct btnode* n)
{
	if(tree==NULL)
		return 0;
	if(tree==n)
		return 1;
	return IsNodeInTree(tree->l,n)||IsNodeInTree(tree->r,n);
}

//checking common ancestor of two nodes a and b
struct btnode* common_ancestor(struct btnode * tree,struct btnode * a, struct btnode * b)
{
	struct btnode * temp;	
	if(IsNodeInTree(tree,a) ==1 && IsNodeInTree(tree,b)==1)
	{
		if((IsNodeInTree(tree->l,a) ==1 && IsNodeInTree(tree->r,b)==1)||IsNodeInTree(tree->r,a)==1 && IsNodeInTree(tree->l,b)==1)
		{
			return tree;
		}
		else if(IsNodeInTree(tree->l,a) ==1 && IsNodeInTree(tree->l,b)==1)
		{
			temp=common_ancestor(tree->l,a,b);
			return temp;
		}
		else if(IsNodeInTree(tree->r,a) ==1 && IsNodeInTree(tree->r,b)==1)
		{
			temp=common_ancestor(tree->r,a,b);
			return temp;
		}
	}
	else
	{
		return NULL;
	}
}

int main()
{
	struct btnode *one,*two,*three,*four,*five,*six,*seven,*temp;
	one=initNode(1);
	two=initNode(2);
	three=initNode(3);
	four=initNode(4);
	five=initNode(5);
	six=initNode(6);
	root=one;
	//one node outside tree
	seven=initNode(7);
	
	//set the tree
	one->l=two;
	one->r=three;
	three->l=four;
	three->r=six;
	four->l=five;

	//Checking if node belongs to the tree
	printf("node four in tree:%d\n",IsNodeInTree(root,four));	
	printf("node six in tree:%d\n",IsNodeInTree(root,six));	

	//checking what is common ancestor of node 5 and 6 
	temp=common_ancestor(root,five,six);
	if(temp != NULL)
	{
		printf("Common ancestor of 5 and 6 is:%d\n",temp->val);
	}
	else
		printf("Common ancestor does not exist!\n");
	
	//checking what is common ancestor of node 3 and 7 
	temp=common_ancestor(root,three,seven);
	if(temp != NULL)
	{
		printf("Common ancestor of 3 and 7 is:%d\n",temp->val);
	}
	else
		printf("Common ancestor does not exist!\n");
}
	
