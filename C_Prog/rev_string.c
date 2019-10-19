#include<stdio.h>
#include<string.h>
int main(void)
{
	/*	
	char *str="perwez";
	for (int i = (strlen(str)-1); i>=0; i--)
	{
		printf("%c",str[i]);
	}
	*/
	char *str = "\0";
	char *rev = "\0";
	int i =0,j,k;

	printf("Enter a string : ");
	scanf("%s",str);
	printf("Original string is %s",str);

	while(str[i] != '\0')
	{
		k = (++i)-1;
	}
	for(j = 0; j<=i; j++)
	{
		rev[j] = str[k];
		k--;
	}
	printf("\nReverse string is %s\n",rev);
	
	return 0;	

}
