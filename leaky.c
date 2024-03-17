#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, s=0, op, bsize, isize;
	printf("Enter the no of data packets: ");
	scanf("%d", &n);
	printf("Enter the bucket size: ");
	scanf("%d",&bsize);
	printf("Enter the output flowsize: ");
	scanf("%d",&op);
	for(int i=0; i<n;i++)
	{
		int r=rand()%2;
		if(r)
		{
			printf("\n Packet received !");
			isize = rand()%10 +1;
			printf("\n Receiving packet size: %d",isize);
			if(isize+s<=bsize)
			{
				s+=isize;
				printf("\n Buffer Contains %d Bytes",s);
			}
			else
			{
				printf("\n packet Lost! ");
				printf("\n size of packet lost: %d bytes", s+isize-bsize);
				s= bsize;	
			
			}
		}
		printf("\n Transmitted packet size: %d ", (s>op)?op:s);
		s= (s-op>0)?s-op:0;
		printf("\n Level of buffer %d bytes",s);
	}
return 0;
}
