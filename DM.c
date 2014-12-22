#include"RTSchedule.h"

/*
	DM Scheduling
*/
void DM(struct TaskSeti* pTaskSeti)
{
	int iterator;
	float Utilization=0,UDM=0;

	printf("\n\n  --DM BEGINS--\n");
	
	//Sorting for priority by deadline
	SortByindex(pTaskSeti,1);

	//Utilization
	for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
	{
		Utilization+=pTaskSeti->SubTask[iterator][0]/pTaskSeti->SubTask[iterator][2];
	}
	printf("Utilization is %f\n",Utilization);

	//UDM
	{
		float n=pTaskSeti->NumTask;
		UDM=n*(pow(2,1/n)-1);
		printf("UDM is %f\n",UDM);
	}

	if(Utilization<=UDM)
		printf("DM is schedulable");
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
				printf("Worki>Time for i=%d.\n DM is uncschedulable\n",tempi);
				return;
			}
		}
		printf("DM is schedulable");
	}
	printf("\n  --DM ENDS--\n\n");
}