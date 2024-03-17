#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int data[7], rec[7],i,c1,c2,c3,c;
printf("Enter the 4 bit message with space: ");
scanf("%d%d%d%d", &data[0], &data[1], &data[2], &data[4]);
data[6]=data[0]^data[2]^data[4];
data[5]=data[0]^data[1]^data[4];
data[3]=data[0]^data[1]^data[2];
printf("The encoded bits are: ");
for(i-0;i<7;i++)
{
printf("%d",data[i]);
}
for(i=0;i<7;i++)
{
rec[i]=data[i];
}
srand(time(NULL));
rec[6]=rand()%2;
printf("\n%d=rand\n",rec[6]);
printf("\nreceived data:\n");
for(i=0;i<7;i++)
{
printf("%d",rec[i]);
}
c1= rec[6]^rec[4]^rec[2]^rec[0];
c2= rec[5]^rec[4]^rec[1]^rec[0];
c3= rec[3]^rec[2]^rec[1]^rec[0];
c= c3*4 + c2*2 +c1;
if(c==0)
{
printf("\n No errors");

}
else
{
printf("\n error position:%d",7-c);
printf("\n correct message: \n");
if(rec[7-c]==0)
{
rec[7-c]=1;
}
else{
rec[7-c]=0;
}
for(i=0;i<7;i++)
{
printf("%d", rec[i]);
}
}

}
