//store a binary tree(not bst) in file and retrieve it
//please read this 
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

void write_to_file(FILE *fp, int * a, int len)
{
	int temp, i = 0;
	char str[10];
	while (i < len)
	{
		memset(str, 0, sizeof(str));
		sprintf(str, "%d", a[i]);
		printf("%d, ", sizeof(int));
		fwrite(str, sizeof(int), 1, fp);
		i++;
	}
}

int * create_array_from_file(FILE * fp)
{
	int temp=0;
	char str[10] = { 0 };
	int ret_arr[] = { 1, 2, 3 };
	while (!feof(fp))
	{
		memset(str, 0, sizeof(str));
		fread(str, sizeof(int), 1, fp);
		temp = atoi(str);
	}
	return ret_arr;//dummy array as of right now
}

int main()
{
	FILE * fp;
	int * ar;
	int arr[] = { 1, 2, 3, 4, NULL, NULL, 5 };
	root = create_node(1);
	root->l = create_node(2);
	root->r = create_node(3);
	root->l->r = create_node(4);
	fp = fopen("abc.txt", "w");

	//create array from tree (level order traversal array)
	{
		//to do
	}

	//write the array to file
	write_to_file(fp,arr,sizeof(arr)/sizeof(int));
	fclose(fp);
	fp = fopen("abc.txt", "r");
	
	//read array from the file
	ar= create_array_from_file(fp);
	fclose(fp);

	//create tree from array
	{
		// to do
	}

	return 0;
}