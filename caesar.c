#include<stdio.h>
int main()
{
int i, key;
char msg[100], ch;
printf("Enter the message to encrypt : ");
scanf("%s", msg);
printf("Enter the key: ");
scanf("%d",&key);
for(i=0;msg[i]!='\0';i++)
{
	ch=msg[i];
	if(ch>='a'&&ch<='z'){
		ch+=key;
	if(ch>'z')
		ch=ch-'z'+'a'-1;
	msg[i]=ch;
	}
	else if(ch>='A'&&ch<='Z')
	{
	ch+=key;
	if(ch>'Z')
	ch=ch-'Z'+'A'-1;
	msg[i]=ch;
}
}

printf("\n Encrypted message: %s", msg);
for(i=0;msg[i]!='\0';i++)
{
	ch=msg[i];
	if(ch>='a'&&ch<='z'){
		ch-=key;
	if(ch<'a'){
	ch=ch+'z'-'a'+1;
}
msg[i]=ch;
}
else if(ch>='A'&&ch<='Z')
{
	ch-=key;
	if(ch<'A')
	ch=ch+'Z'-'A'+1;
msg[i]=ch;
}
}
printf("Decrypted message: %s", msg);
}
