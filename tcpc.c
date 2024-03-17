#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(){
	int servfd,connfd;
	struct sockaddr_in serv;
	bzero(&serv,sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1234);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	servfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("\nSocket created");
	connfd=connect(servfd,(struct sockaddr*)&serv,sizeof(serv));
	if(connfd!=0){
		printf("\nConnection with server failed\n");
		exit(0);
	}
	else{
		printf("\nConnected to the server!!!\n\n");
	}
	//file operations
	char buff[1024];	
	bzero(&buff,sizeof(buff));
	int len = sizeof(serv);
	printf("\nEnter the file name: ");
	scanf("%s",buff);
	send(servfd,buff,sizeof(buff),0);
	//FILE *fp = fopen("receivedFile.txt","w");
	while(1){
		bzero(&buff,sizeof(buff));
		recv(servfd,buff,sizeof(buff),0);
		//fprintf(fp,"%s",buff);
		printf("%s",buff);
	}
	printf("\nFile received successfully !");
	return 0;
}
