#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 80
#define PORT 8080

void func (int connfd)
{
	char buff[MAX];
	int n;
	while(1)
	{
		bzero(buff, MAX);
		read(connfd, buff, sizeof(buff));
		printf("From client: %s\t to client: ", buff);
		bzero(buff, MAX);
		n=0;
		while((buff[n++]= getchar())!= '\n');
		write(connfd, buff, sizeof(buff));
		if (strncmp("exit", buff,4)==0)
		{
		printf("\n Server exit...\n");
		break;
		}
	}

}

int main()
{
int sockfd, len;
struct sockaddr_in serv_addr, cli;
sockfd = socket(AF_INET, SOCK_STREAM,0);
if(sockfd ==1)
{
	printf("Socket created failed..|n");
	exit(0);
}
printf("Socket successfully created...\n");
bzero(&serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
if((bind(sockfd, (struct sockaddr*)& serv_addr, sizeof(serv_addr)))!=0)
{
	printf("Socket bind failed \n ");
	exit(0);
}
printf("Socket bind success\n");
if((listen(sockfd,5))!=0)
{
	printf("Listen failed...\n");
	exit(0);
}
printf("Server Listening");
len = sizeof(cli);
int connfd = accept(sockfd, (struct sockaddr*) &cli,&len);
if (connfd<0)
{
printf("Server accept failed \n ");
exit(0);
}
printf("Server accepted the client\n ");
func(connfd);
close(sockfd);
}
