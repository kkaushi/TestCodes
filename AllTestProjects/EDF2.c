#include"RTSchedule.h"


/*
	EDF 
*/
void EDF(struct TaskSeti* pTaskSeti)
{
	int iterator;
	float Utilization=0,Density=0;
	float LoadingFactor=0;//u[t1,t2]
	float ProcessorDemandSynchronous=0;//h
	int DeadlinelessThanPeriodi=0;
	printf("\n\n  --EDF BEGINS--\n");

	//Utilization
	for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
	{
		Utilization+=pTaskSeti->SubTask[iterator][0]/pTaskSeti->SubTask[iterator][2];
	}
	printf("Utilization is %f\n",Utilization);

	if(Utilization>1)
	{	
		printf("Utilization >1 so EDF is not schedulable");
		return;
	}
	//Utilization<1
	else
	{
		//Check Deadline condition
		for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
		{
			if(pTaskSeti->SubTask[iterator][1]<pTaskSeti->SubTask[iterator][2])	
			{
				//DeadlinelessThanPeriodi = 1 if for any i, Di<Pi
				DeadlinelessThanPeriodi=1;
				break;
			}
			//Utilization <=1 && Di>=Ti
			if(DeadlinelessThanPeriodi==0)
			{
				printf("EDF is schedulable");
				return;
			}
		}
		//Utilization <=1 && Di<Ti
		if(DeadlinelessThanPeriodi==1)
		{
			//Testing Sufficient Condition ie Density
			for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
			{
				Density+=pTaskSeti->SubTask[iterator][0]/minimum(pTaskSeti->SubTask[iterator][2],pTaskSeti->SubTask[iterator][1]);
			}
			//printf("Density is %f\n",Density);
			//Utilization <=1 && Di<Ti && Density<=1
			if(Density<=1)
			//if(0)
			{
				printf("EDF is schedulable");
				return;
			}
			else
			//Utilization <=1 && Di<Ti && Density>1
			//Calculating Loading Factor and testing condition
			{
				//t1 is the phase of current task
				//t2 is the deadline of current task
				float t1=0,t2=0;
				for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
				{
					int tempi=0;
					float ProcessorDemand_t1t2=0;
					float LoadingFactor_t1t2=0;
					t1=pTaskSeti->SubTask[iterator][3];
					t2=pTaskSeti->SubTask[iterator][1];
					for(tempi=0;tempi<pTaskSeti->NumTask;tempi++)
					{
						if(t1<=pTaskSeti->SubTask[tempi][3] && pTaskSeti->SubTask[tempi][1]<=t2)
						{
							ProcessorDemand_t1t2+=pTaskSeti->SubTask[tempi][0];
						}
					}
					LoadingFactor_t1t2=ProcessorDemand_t1t2/t2-t1;
					if(LoadingFactor_t1t2>1)
					{
						//DoBusyPeriodAnalysis
						printf("EDF is not schedulable\n");
						return;
					}
				}
				//Utilization<1 && Di<Ti && LoadingFactor_t1t2<1 
				//Do Busy period analysis
				{
					int level=0;//level of Busy period analysis
					float L[1000]={0};//Assuming maximum level 1000
					//Computing Synchronous busy period
					for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
						//L[0]=sup(1,n)Ci
						L[level]+=pTaskSeti->SubTask[iterator][1];
					level=1;
					while(L[level]!=L[level-1] && level<=1000)
					{	
						for(iterator=0;iterator<pTaskSeti->NumTask;iterator++)
						{
							L[level+1]=ceil(L[level]/pTaskSeti->SubTask[iterator][2])*pTaskSeti->SubTask[iterator][0];							
						}
						level+=1;
					}
					if(level>=1000)
					{
						printf("EDF not schedulable");
					}
					else
					{
						
						int tempi=0;

						//points array for deadline instants < L for testing Loading factor
						int points[1000]={0};
						int index=0;
						
						//Array of minimum values for points array
						int minValues[1000]={0};
						int tempMinVal=0;
						for(iterator=0;iterator<=pTaskSeti->NumTask;iterator++)
							minValues[iterator]=pTaskSeti->SubTask[iterator][3];
						
						//Generating points
						for(iterator=0;iterator<=level+1;iterator++)
						{
							for(tempi=0;tempi<=pTaskSeti->NumTask;tempi++)
							{
								if(tempMinVal<minValues[tempi])
								{
									tempMinVal=minValues[tempi];
									index=tempi;
								}
							}
							points[iterator]=tempMinVal;
							//adding period
							minValues[index]+=pTaskSeti->SubTask[index][2];							
						}
						//Generating loading factor at critical points
						{
							float t1=0,t2=0;
							for(iterator=0;iterator<level+1;iterator++)
							{
								int tempi=0;
								float ProcessorDemand_t1t2=0;
								float LoadingFactor_t1t2=0;
								//t1=pTaskSeti->SubTask[iterator][3];
								t1=0;
								//t2=pTaskSeti->SubTask[iterator][1];
								t2=minValues[iterator];
								for(tempi=0;tempi<pTaskSeti->NumTask;tempi++)
								{
									if(t1<=pTaskSeti->SubTask[tempi][3] && pTaskSeti->SubTask[tempi][1]<=t2)
									{
										ProcessorDemand_t1t2+=pTaskSeti->SubTask[tempi][0];
									}
								}
								LoadingFactor_t1t2=ProcessorDemand_t1t2/t2-t1;
								if(LoadingFactor_t1t2>1)
								{
									printf("EDF is not schedulable\n");
									return;
								}
							}
							printf("EDF is schedulable");

						}
					}
				}
			}
		}
	}
	printf("\n  --EDF ENDS--\n\n");
}