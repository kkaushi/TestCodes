//Use this struct to mirror a binary tree
#include<stdio.h>

typedef struct my_struct{
	int val;
	struct my_struct * lc;
	struct my_struct * rc;
}node;


void main(){
	node mytree_l = {2,NULL,NULL};
	node mytree_r={6,NULL,NULL};
	node mytree = {4,&mytree_l,&mytree_r};
	printf("Root Node:%d\nLeft Child:%d\nRight Child:%d\n",mytree.val,mytree_l.val,mytree_r.val);
}