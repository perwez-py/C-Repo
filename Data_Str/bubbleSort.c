#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 5
int array[n] = {50,10,60,20,40};
int main()
{
	
	int i,j,temp;

	for(i = 0; i<n; i++)
	{
		for(j = 0; j < n-i; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}	
		}
		
		printf("Sorted array is %d\n",array[j]);
	}

	return 0;
}
