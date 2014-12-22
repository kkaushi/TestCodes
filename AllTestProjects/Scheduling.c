//#include <stdio.h>
#include"RTSchedule.h"

float minimum(float value1, float value2)
{
	if(value1<=value2)
		return value1;
	else
		return value2;
}

/*
	Swap methods swaps two subtasks in a taskset at indexes index1 and index2

*/
void Swap(struct TaskSeti *pTi,int index1, int index2)
{
	int i=-1;
	float temp[4]={0};
	for(i=0;i<=3;i++)
	{
		temp[i]=pTi->SubTask[index1][i];
		pTi->SubTask[index1][i]=pTi->SubTask[index2][i];
		pTi->SubTask[index2][i]=temp[i];
	}
}


/*
	
	SortByindex method sort the Tasks of a Taskset on the basis of index
	index is -
		0 for ei
		1 for di
		2 for Ti
		3 for phasei
		4 for given fixed priority
*/
void SortByindex(struct TaskSeti *pTi,int index)
{
	int c=0,d=0,n= pTi->NumTask;

	for (c = 0 ; c < ( n - 1 ); c++)
	{
		for (d = 0 ; d < n - c - 1; d++)
		{
			if(index==4)
			{
				if(pTi->TaskPriority[d]>pTi->TaskPriority[d+1])
				{
					int tempVal=0;
					Swap(pTi,d,d+1);
					//Changing values in 
					tempVal=pTi->TaskPriority[d];
					pTi->TaskPriority[d]=pTi->TaskPriority[d+1];
					pTi->TaskPriority[d+1]=tempVal;
				}
			}
			else
			{
				if (pTi->SubTask[d][index]>pTi->SubTask[d+1][index])
				{
					Swap(pTi,d,d+1);				
				}
			}
		}
	}
}


int main()
{
	struct TaskSeti *pTi;
	FILE * fp;
	char line[100];

	//DataSet.txt is the source file for Random Text data in the same format as given in the assignment
	fp=fopen("DataSet.txt","r+");
	printf("  -- Scheduling Feasibility Analysis --\n");
	
	//malloc
	pTi=(struct TaskSeti *)malloc(sizeof(struct TaskSeti));	
	
	//reading data set structure wise
	while(fgets(line,100,fp)!=NULL)
	{
		int temp=0;
		float tempfloat;
		char tempchar=0;
		int tempint=0;
		//reading no of tasks
		pTi->NumTask=atoi(line);
		//reading WCET, deadline, Period and Phase 
		for(temp=0;temp<pTi->NumTask;temp++)
		{
			line[0]=0;
			fscanf(fp,"%f",&tempfloat);
			pTi->SubTask[temp][0]=tempfloat;
			fscanf(fp,"%c",&tempchar);
			fscanf(fp,"%f",&tempfloat);
			pTi->SubTask[temp][1]=tempfloat;
			fscanf(fp,"%c",&tempchar);
			fscanf(fp,"%f",&tempfloat);
			pTi->SubTask[temp][2]=tempfloat;
			fscanf(fp,"%c",&tempchar);
			fscanf(fp,"%f",&tempfloat);
			pTi->SubTask[temp][3]=tempfloat;
		}
		for(temp=0;temp<pTi->NumTask;temp++)
		{
			fscanf(fp,"%d",&tempint);
			pTi->TaskPriority[temp]=tempint;
		}
		//calling methods
		/*
			Checking each method for schedulability
		*/
		EDF(pTi);
		RM(pTi);
		DM(pTi);
		FP(pTi);
		break;
	}
	
	getch();
	return 0;
}