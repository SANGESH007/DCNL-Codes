#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	int servfd,clifd;
	struct sockaddr_in serv;
	bzero(&serv,sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1234);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	servfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("\nSocket created");
	//file operations
	char buff[1024];	
	bzero(&buff,sizeof(buff));
	int len = sizeof(serv);
	printf("\nEnter the file name: ");
	scanf("%s",buff);
	sendto(servfd,buff,sizeof(buff),0,(struct sockaddr*)&serv,len);
	//FILE *fp = fopen("receivedFile.txt","w");
	while(1){
		bzero(&buff,sizeof(buff));
		recvfrom(servfd,buff,sizeof(buff),0,(struct sockaddr*)&serv,&len);
		//fprintf(fp,"%s",buff);
		printf("%s",buff);
	}
	printf("\nFile received successfully !");
	return 0;
}
