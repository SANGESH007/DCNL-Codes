#include<stdio.h>
#include<string.h>
int main()
{
char msg[100], key[100];
int i, j;
printf("Enter the message: ");
scanf("%s", msg);
printf("Enter the key: ");
scanf("%s", key);
int mlen= strlen(msg), klen=strlen(key);
char nkey[mlen], emsg[mlen], dmsg[mlen];
for(i=0,j=0;i<mlen; i++,j++)
{
if(j==klen)
	j=0;
nkey[i]=key[j];
}
nkey[i]='\0';

for(i=0;i<mlen;i++)
	emsg[i]=((msg[i]+nkey[i])%26)+'A';
emsg[i]='\0';

for(i=0;i<mlen;i++)
	dmsg[i]=((emsg[i]-nkey[i]+26)%26)+'A';
dmsg[i]='\0';
printf("\n Message: %s", msg);
printf("\n key: %s", key);
printf("\n New generated key: %s", nkey);
printf("\n Encrypted message: %s", emsg);
printf("\n Decrypted message: %s", dmsg);
}
