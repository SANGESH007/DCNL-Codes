#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 100
int gcd(int n1, int n2)
{
if(n2!=0)
	return gcd(n2,n1%n2);
else
	return n1;
}
int main()
{
char msg[SIZE];
int p, q, e, phi, n, c[30], m[3], d;
printf("Enter the message: ");
scanf("%s", msg);
printf("Enter the prime numbers: ");
scanf("%d%d",&p,&q);
n=p*q;
phi= (p-1)*(q-1);
for(e=2;(e<phi)&&(gcd(e,phi)!=1);e++);
for(int i=2;i<phi;i++)
	if((i*e)%phi==1)
	{
		d=i;
		break;
	}
printf("\n Public key: %d", e);
printf("\n Private key: %d", d);
printf("\n Encrypted message:\n");
for(int i=0;i<strlen(msg);i++)
{
c[i]=fmod(pow((double)msg[i]-'A'+1,e),n);
printf("%c", (int)(c[i]+ 'A'-1));

}
printf("\n Decrypted message: \n");
for(int i=0;i<strlen(msg);i++)
{
m[i]= fmod(pow(c[i],d),n);
printf("%c", (char)(m[i]+ 'A'-1));
}
return 0;
}

