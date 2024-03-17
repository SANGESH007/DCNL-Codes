#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main()
{

int n, N, nt=0;
srand(time(NULL));
printf("Enter the number of frames: ");
scanf("%d",&n);
printf("Enter the window size: ");
scanf("%d", &N);
int i=1;
while(i<=n)
{
int x=0;
for(int j=i; j<i+N&&j<=n;j++)
{
printf("\n Sent frame %d",j);
nt++;
}
for(int j=i;j<i+N&&j<=n;j++)
{
int f=rand()%2;
if(!f)
{
printf("\n Acknowledgement for frame %d",j);
x++;
}
else
{
printf("\n Frame %d",j);
printf("\t Not received \n");
printf("Retransmitted window");
break;
}
}
printf("\n");
i+=x;
}
printf("Total number of Transmissions: %d", nt);
return 0;
}
