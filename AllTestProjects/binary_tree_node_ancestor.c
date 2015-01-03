#include<stdio.h>

typedef struct node
{
	int value;
	struct node * left;
	struct node * right;
} nd;

nd * create_nd(int v)
{
	nd * temp = (nd *)malloc(sizeof(nd));
	temp->value = v;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int print_all_ancestor(nd * n, int val)
{
	if (n == NULL)
		return 0;

	if (n->value == val)
		return 1;
		//printf("%d\n", val);
	
	if (print_all_ancestor(n->left,val) || print_all_ancestor(n->right,val))
	{
		printf("%d\n", n->value);
		return 1;
	}
	return 0;
}

void main()
{
	nd * root = create_nd(1);
	root->left = create_nd(2);
	root->right = create_nd(3);
	root->left->left = create_nd(4);
	root->left->right = create_nd(5);
	root->left->left->left = create_nd(7);
	print_all_ancestor(root, 7);
}