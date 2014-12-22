#include<stdio.h>
#include<math.h>

int recur(int an, int c, int pi1, int ci1, int pi2, int ci2)
{
	int ann=-1;
	//int t=0;
	//t=ceil((double)an/pi1);
	ann=c+ceil((double)an/pi1)*ci1+ceil((double)an/pi2)*ci2;
	if(ann!=an)
		recur(ann,c,pi1,ci1,pi2,ci2);
	return ann;
}

void main()
{
	int wcrt=-1;
	wcrt= recur(12, 1, 10, 4, 11, 7);
}