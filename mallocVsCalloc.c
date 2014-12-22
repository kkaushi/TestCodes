#include<stdio.h>
#include<memory.h>


void rotateArr(double *A, int M)
{
	int i;
	double * temp=(double *)malloc(M*sizeof(double));
	for(i=1;i<M;i++)
	{
		temp[i]=A[i-1];
	}
	temp[0]=A[M-1];
	for(i=0;i<M;i++)
	{
		A[i]=temp[i];
	}
	free(temp);
}


void CreateMat(int M)
{
	int i,j;
	double *A = (double*) malloc(M*M*sizeof(double));
	double Arr[5];

	for(i=0;i<M;i++)
		Arr[i]=(double)i+1;

	for(i=0;i<M;i++ ){
		if(i!=0)
			rotateArr(Arr,M);
		for(j=0;j<M;j++){
			A[j*M+i]=Arr[j];
		}
	}

	for(i=0;i<M;i++ ){
		for(j=0;j<M;j++){
			printf("%f\t",A[i*M+j]);
		}
		printf("\n");
	}
	
}
void main()
{
	int * ptr_malloc,*ptr_calloc;
	int i;

	ptr_malloc=malloc(10*sizeof(int));
	ptr_calloc=calloc(10,sizeof(int));
	//memset(ptr_calloc,0,10);

	for(i=0;i<10;i++)
	{
		//printf("%d\n",*(ptr_calloc));
		//ptr_calloc++;
		printf("%d, %d\n",*(ptr_malloc+i),*(ptr_calloc+i));
	}

	CreateMat(5);
}