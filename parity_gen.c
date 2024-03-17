#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char data[20], rdata[20];
int datalen;
int check(char data[20]);
int main()
{

int i, count=0, tflag, rflag,test;
printf("Enter Total Bits of data: ");
scanf("%d",&datalen);
printf("Enter the data: ");
scanf("%s",data);
tflag=check(data);
puts("\nReceived data: \n");
strcpy(rdata,data);
for(i=0;i<datalen;i++)
{
printf("%c",rdata[i]);

}
srand(time(NULL));
test=rand()%2;
printf("\nrand=%d\n", test);
rdata[0]=(test>0.5)?'1':'0';
printf("Received data after replacing rand");
for(i=0;i<datalen;i++)
{
printf("%c",rdata[i]);

}
rflag=check(rdata);
if(tflag==rflag)
{
printf("\nSuccess! the received message has no error");

}
else
{
printf("\n sorry, the received data has error");

}
return 0;
}

int check(char data[20])
{
int i, epar, opar, count=0;
for(i=0;i<datalen;i++)
{
if(data[i]=='1')
{
count++;
}
}
printf("\ncount=%d", count);
if(count%2)
{
epar=1;
opar=0;
}
else
{
epar=0;
opar=1;
}
printf("Even parity:%d, odparity:%d", epar,opar);
return opar;
}

