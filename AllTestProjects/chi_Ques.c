#include<stdio.h>

int check(int j, int i, int val, int **mat)
{
	int t = 0;
	for (; t < j; t++)
	{
		if (mat[t][i] == val)
			return t+1;
	}
	return 0;
}

int in_row(int j, int i, int val, int **mat)
{
	int t = 0;
	for (; t < i; t++)
	{
		if (mat[j][t] == val)
			return 1;
	}
	return 0;
}

int in_col(int j, int i, int val, int **mat)
{
	int t = 0;
	for (; t < j; t++)
	{
		if (mat[t][i] == val)
			return 1;
	}
	return 0;
}

void schedule(int **mat, int n)
{
	int i, j, t, position = 0, c = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			//populate first row
			if (j == 0)
			{
				for (t = 0; t < n-1; t++)
				{
					mat[j][t] = t + 2;
				}
			}
			else
			{
				position = 0;
				position = check(j, i, j + 1, mat);
				if (position)
				{
					mat[j][i] = position;
					continue;
				}
				else
				{
					for (c = 0; c < n; c++)
					{
						if (c == j)
							continue;
						if (!in_row(j, i, c+1, mat) && !in_col(j, i, c+1, mat))
						{
							mat[j][i] = c+1;
							break;
						}
					}
				}
			}

			


		}
	}

}

int main()
{
	int **mat, i;
	int nteams=0,ndays=0;
	printf("Enter #teams\n");
	scanf("%d", &nteams);
	ndays = nteams - 1;

	if (nteams == 0 || nteams == 1)
	{
		printf("Cant schedule\n");
		return -1;
	}
		
	
	mat = (int *)malloc(nteams*sizeof(int *));
	for (i = 0; i < nteams; i++)
	{
		mat[i] = (int *)malloc(ndays *sizeof(int));
	}

	schedule(mat,nteams);
	printf("hello\n");
	//i am not freeing matrix right now
}