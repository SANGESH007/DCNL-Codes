#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void main()
{
int i=1, j=1, n,x, x1=10, x2;
printf("Enter the no of frames: ");
scanf("%d", &n);
while(n>0)
{
printf("\n Sending frame %d: ",i);
srand(x1++);
x= rand()%10;
if((x%2)==0)
{
for(x2=1;x2<2;x2++)
{
	printf("\n Acknowledgement not receiving");
	printf("\nRetransmittig bit %d",j);
	sleep(x2);
}
	printf("\n Retransmitting frame %d",i);
}
printf("\n Acknowledgement for frame %d",j);
n-=1;
i++; j++;
}
printf("\n End of stop and wait protocol");
}
