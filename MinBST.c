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
struct tree_node * MinBST(int *a, int l, int r)
{
	int mid=(l+r)/2;
	struct tree_node * temp=(struct tree_node *) malloc(sizeof(struct tree_node));
	temp->val=a[mid];	
	temp->l=NULL;
	temp->r=NULL;
	if(l<=mid-1)	
		temp->l=MinBST(a,l,mid-1);
	if(mid+1<=r)		
		temp->r=MinBST(a,mid+1,r);
	return temp;
}
int main()
{
	int arr[8]={1,2,3,4,5,6,7,8};
	struct tree_node * head;
	head=MinBST(arr,0,7);
	inorder(head);
	printf("\n");
}
