//headers
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

//Defining base structure
struct TaskSeti
{
	int NumTask;				// Num of Tasks in current Taskset
	float SubTask[100][4];		// An array [ei, di, pi, ph]	ei/Ci=Worst Case Execution Time, di/Di=Deadline, pi/Ti=Period, ph=phase
	int TaskPriority[100];		// Priority of Tasks in Taskset
};

//Methods
float minimum(float,float);
void EDF(struct TaskSeti*);
void RM(struct TaskSeti*);
void Swap(struct TaskSeti *, int, int);
void SortByindex(struct TaskSeti *,int );
void DM(struct TaskSeti*);
void FP(struct TaskSeti* pTaskSeti);