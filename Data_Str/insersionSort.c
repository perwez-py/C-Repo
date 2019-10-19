#include<stdio.h>

#define size 10

int main(void)
{
	int arr[size] = {7,9,3,10,18,12,30,16,35,70};
	
	int i,j,check;

	for(i = 1; i<size-1; i++)
	{
		check = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > check)
		{
			arr[j+1] = arr[j];	
			j = j - 1;	
		}
		arr[j+1] = check;
	}
	printf("sorted array is %d\n",arr[i]);
	return 0;
}
