#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){
	int servfd;
	struct sockaddr_in serv, cli;
	bzero(&serv,sizeof(serv));
	serv.sin_family= AF_INET;
	serv.sin_port = htons(1234);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	servfd = socket(AF_INET,SOCK_STREAM, 0);
	printf("\nSocket created\n");
	bind(servfd,(struct sockaddr*)&serv,sizeof(serv));
	printf("\nSocket binded\n");
	listen(servfd, 20);
	int lens = sizeof(cli);
	accept(servfd, (struct sockaddr*)&cli, &lens);
	FILE *fp;
	char buff[1024];
	bzero(&buff,sizeof(buff));
	int len = sizeof(serv);
	recv(servfd,buff,sizeof(buff),0);
	fp = fopen(buff,"r");
	printf("\nFile opened\n");

	while((fgets(buff,sizeof(buff),fp))!=NULL){
		send(servfd,buff,sizeof(buff),0);
		bzero(&buff,sizeof(buff));
	}
	printf("\nFile sent successfully");
	return 0;
	
}
