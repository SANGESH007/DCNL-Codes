#include<stdio.h>
#include<stdlib.h>
char data[40], divi[40], temp[20], total[100];
int i, j ,datalen, divlen, len, flag=1;
void check();
int main()
{
printf("Enter the total bits of data: ");
scanf("%d", &datalen);
printf("Enter the total bits of division: ");
scanf("%d",&divlen);
len= datalen+divlen-1;
printf("enter the data: ");
scanf("%s",data);
printf("enter the divisor: ");
scanf("%s",divi);
for(i=0;i<datalen;i++)
{
total[i]=data[i];
temp[i]=data[i];
}
for(i=datalen;i<len;i++)
{
total[i]='0';
}
check();
for(i=0;i<divlen;i++)
{
temp[i+datalen]=data[i];
}
printf("\nTransmitted code: %s", temp);
printf("\nEnter the received data: ");
scanf("%s",total);
check();
for(i=0;i<divlen-1;i++)
{
if(data[i]=='1')
{
flag=0;
break;
}
}
if(flag==1)
{
printf("\nsuccess!");
}
else
{
printf("\n Received data is erroreous");
}
return 0;

}

void check()
{
for (j=0; j<divlen;j++)
{
data[j]=total[j];
}
while(j<=len)
{
if(data[0]=='1')
{
for(i=1;i<divlen;i++)
{
data[i]= (data[i]==divi[i])?'0':'1';
}
}
for(i=0;i<divlen-1;i++)
{
data[i]= data[i+1];
}
data[i]=total[j++];
}
}

