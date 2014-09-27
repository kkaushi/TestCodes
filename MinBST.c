#include<stdio.h>
#include<stdlib.h>

struct tree_node
{
	int val;
	struct tree_node * l;
	struct tree_node * r;
};

void inorder(struct tree_node * n)
{
	if(n==NULL)
		return;
	inorder(n->l);
	printf("%d",n->val);
	inorder(n->r);
	return;
}
void MinBST(int *a, int l, int r,struct tree_node * n)
{
	int mid=(l+r)/2;
	n=(struct tree_node *) malloc(sizeof(struct tree_node));
	n->val=a[mid];	
	n->l=NULL;
	n->r=NULL;
	if(l<=mid-1)	
		MinBST(a,l,mid-1,n->l);
	if(mid+1<=r)		
		MinBST(a,mid+1,r,n->r);
	return;
}

int main()
{
	int arr[8]={1,2,3,4,5,6,7,8};
	struct tree_node * head;
	MinBST(arr,0,7,head);
	//inorder(head);
}
