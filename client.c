#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#define MAX 80
#define PORT 8080

void func (int sockfd)
{
	char buff[MAX];
	int n;
	while(1)
	{
		bzero(buff, sizeof(buff));
		n=0;
		printf("Enter the string: ");
		while((buff[n++]= getchar())!= '\n');
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff));
		printf("From server: %s", buff);
		if (strncmp("exit", buff,4)==0)
		{
		printf("\n Server exit...\n");
		break;
		}
	}

}

int main()
{
int sockfd, connfd;
struct sockaddr_in serv_addr;
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
//serv_addr.sin_addr.s_addr = inet_addr("client ip address");
serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
connfd = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
if(connfd!=0)
{
printf("connection with server failes\n");
exit(0);
}
else
{
printf("connection with server success\n");
}
printf("Server accepted the client\n");
func(sockfd);
close(sockfd);
}
