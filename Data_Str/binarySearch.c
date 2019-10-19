#include<stdio.h>
#define n 11
int main()
{
	int arr[n] ={3,7,17,35,44,54,60,77,86,91,98};
	int low,high,mid,x;
	low = 0;
	high = n-1;
	printf("Please find the location of : ");
	scanf("%d",&x);
	while(low <= high)
	{
		mid = (low+high)/2;
		if(x < arr[mid])
		{
			high = mid - 1;	
		}
		else if(x > arr[mid])
		{
			low = mid + 1;
		}
		else if(x == arr[mid])
		{
			printf("Location of index %d\n",mid);
			break;
		}
	}
	return 0;	
}
