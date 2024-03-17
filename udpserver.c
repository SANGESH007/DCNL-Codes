#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){
	int servfd;
	struct sockaddr_in serv;
	bzero(&serv,sizeof(serv));
	serv.sin_family= AF_INET;
	serv.sin_port = htons(1234);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	servfd = socket(AF_INET,SOCK_DGRAM, 0);
	printf("\nSocket created\n");
	bind(servfd,(struct sockaddr*)&serv,sizeof(serv));
	printf("\nSocket binded\n");
	FILE *fp;
	char buff[1024];
	bzero(&buff,sizeof(buff));
	int len = sizeof(serv);
	recvfrom(servfd,buff,sizeof(buff),0,(struct sockaddr*)&serv,&len);
	fp = fopen(buff,"r");
	printf("\nFile opened\n");

	while((fgets(buff,sizeof(buff),fp))!=NULL){
		sendto(servfd,buff,sizeof(buff),0,(struct sockaddr*)&serv,len);
		bzero(&buff,sizeof(buff));
	}
	printf("\nFile sent successfully");
	return 0;
	
}
