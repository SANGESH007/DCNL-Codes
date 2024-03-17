#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int p,s,opq,isize,d, token, a=0;
	printf("Enter initial no of tokens: ");
	scanf("%d",&token);
	printf("Enter the buffer size: \n");
	scanf("%d",&d);
	
	for(int i=0; i<10;i++)
	{
		if(token<d)
			++token;
		else
		{
		printf("Maximum token size is reached");
		}
		printf("\n token size: %d", token);
		a= rand()%2;
		if(a)
		{
		isize= rand()%10 +1;
		printf("\n size of incomming packet %d", isize);
		if(isize<=token)
		{
		printf("\n Packet sent");
		token-= isize;
		}
		else
			printf("\n Packet discarded");
		}
	}

}
