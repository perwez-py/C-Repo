#include<stdio.h>
#define n 7
int main(void)
{
	int array[n] = {11,9,15,8,1,7,2};
	int i = 0,j,min,temp;

	//for (i = 0; i<n; i++)
	while(i < n)
	{
		min = i;
		for(j = i+1; j<n; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}	
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		printf("%d\n",array[i]);	
		i++;
	}

	return 0;
}
