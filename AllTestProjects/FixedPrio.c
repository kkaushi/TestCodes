#include"RTSchedule.h"

/*
	Fixed Priority Scheduling
*/
void FP(struct TaskSeti* pTaskSeti)
{
	int iterator=0,tempj=0;
	//fi - Effective utilization for taski
	float fi=0;

	printf("\n\n  --Fixed Priority BEGINS--\n");
	
	//Sorting for priority by given fixed priority
	//index 4 for fixed priority sorting
	SortByindex(pTaskSeti,4);	


	//Determining effective utilization
	for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
	{		
		fi=0;
		for(tempj=0;tempj<pTaskSeti->NumTask;tempj++)
		{
			if(pTaskSeti->SubTask[tempj][2]<=pTaskSeti->SubTask[iterator][1])
				fi+=pTaskSeti->SubTask[tempj][0]/pTaskSeti->SubTask[tempj][2];
			else if(pTaskSeti->SubTask[tempj][2]>pTaskSeti->SubTask[iterator][1])
				fi+=pTaskSeti->SubTask[tempj][0]/pTaskSeti->SubTask[iterator][2];
		}
		if(fi>1)
		{
			printf("fi>1 for Task %d\nFixed Priority not schedulable\n",iterator);
			return;
		}
	}
	printf("Fixed Priority Schedulable\n");
	printf("\n  --Fixed Priority ENDS--\n\n");
}