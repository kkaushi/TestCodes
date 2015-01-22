//given a sorted array, construct bst of min height
//doesnt work for duplicates in array
#include<stdio.h>

typedef struct node
{
	int val;
	struct node * l;
	struct node * r;

}node;

node * create_node(int val)
{
	node * temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	temp->l = NULL;
	temp->r = NULL;
	temp->val = val;
	return temp;
}

node * root;

node * create_tree(int *a, int i, int j)
{
	int l = j - i + 1;
	int left_indx, right_indx;
	node * temp = create_node(a[i+l / 2]);
	if (temp == NULL)
	{
		printf("Cant create tree\n");
	}
	else
	{
		if (i != j)
		{
			left_indx = (l / 2 - 1) >= i ? (l / 2 - 1) : i;//crux1
			if (left_indx == i && temp->val == a[left_indx])//so that root is not passed to child
				temp->l = NULL;
			else
				temp->l = create_tree(a, i, left_indx);
			right_indx = (i + l / 2 + 1) <= j ? (i + l / 2 + 1) : j;//crux2
			if (right_indx == j && temp->val == a[right_indx])
				temp->r = NULL;
			else
				temp->r = create_tree(a,right_indx , j);
		}
		if (i==j)
			temp->val = a[i];
		return temp;
	}
}


int main()
{
	int a[] = { 4, 13, 27, 34, 44, 55, 66 };
	//int a[] = { 1, 2, 3 };
	//int a[] = {1};
	//int a[] = { 1, 2, 3, 4};
	root = create_tree(a, 0, sizeof(a) / sizeof(int)-1);
	printf("Done!\n");
	return 0;
}