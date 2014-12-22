#include<stdio.h>
void printMat(double *A,int M)
{
	int i,j;
	for(i=0;i<M;i++ ){
		for(j=0;j<M;j++){
			printf("%f\t",A[i*M+j]);						
		}
		printf("\n");
	}
}
void ReadFile(int size)
{
	double * Arra;
	FILE * f;
	f = fopen("Matrix.txt", "r");
	Arra=(double *)malloc(sizeof(double)*size*size);
	fread(Arra,sizeof(double),size*size,f);
	fclose(f);
	printMat(Arra,size);	
}
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


void CreateMat(int M,int flag)
{
	int i,j;
	double *A = (double*) malloc(M*M*sizeof(double));
	double *Arr = (double*) malloc(M*sizeof(double));
	FILE *f;
	if(flag==1)
		f = fopen("Matrix1_16384.txt", "w");
	else
		f = fopen("Matrix2_16384.txt", "w");

	for(i=0;i<M;i++)
	{
		if(flag==1)
			Arr[i]=(double)i+1;//change here 
		else
			Arr[i]=(double)i+10;//change here 
	}
	
	for(i=0;i<M;i++ ){
		if(i!=0)
			rotateArr(Arr,M);
		for(j=0;j<M;j++){
			A[j*M+i]=Arr[j];
		}
	}

	for(i=0;i<M;i++ ){
		for(j=0;j<M;j++){
			//printf("%f\t",A[i*M+j]);
			//fprintf(f,"%f",A[i*M+j]);
			fwrite(&(A[i*M+j]),sizeof(double),1,f);
		}
		//printf("\n");
	}
	
	fclose(f);	
}

void main()
{
	CreateMat(16384,1);
	//ReadFile(4);
	printf("Done!\n");
}