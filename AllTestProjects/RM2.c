#include"RTSchedule.h"

/*
	RM Scheduling
*/
void RM(struct TaskSeti* pTaskSeti)
{
	int iterator;
	float Utilization=0,URM=0;

	printf("\n\n  --RM BEGINS--\n");
	
	//Sorting for priority
	SortByindex(pTaskSeti,2);

	//Utilization
	for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
	{
		Utilization+=pTaskSeti->SubTask[iterator][0]/pTaskSeti->SubTask[iterator][2];
	}
	printf("Utilization is %f\n",Utilization);

	//URM
	{
		float n=pTaskSeti->NumTask;
		URM=n*(pow(2,1/n)-1);
		printf("URM is %f\n",URM);
	}

	if(Utilization<=URM)
		printf("RM is schedulable");
	else
	//Do Time Demand Analysis
	{
		int tempi=0,tempj=0;
		for(tempi=pTaskSeti->NumTask-1;tempi>=0;tempi--)
		{
			//time for each task is phasei + deadlinei
			int time=pTaskSeti->SubTask[tempi][1]+pTaskSeti->SubTask[tempi][3];
			int worki=0;
			worki=pTaskSeti->SubTask[tempi][0];
			for(tempj=1;tempj<=tempi-1;tempj++)
			{
				worki+=(ceil(time/pTaskSeti->SubTask[tempj][2]))*pTaskSeti->SubTask[tempj][0];
			}			
			if(worki>time)
			{
				printf("Worki>Time for i=%d.\n RM is uncschedulable\n",tempi);
				return;
			}
		}
		printf("RM is schedulable");
	}
	printf("\n  --RM ENDS--\n\n");
}