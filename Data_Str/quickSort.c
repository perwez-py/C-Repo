#include<stdio.h>
#define size 9

int array[size] = {10,8,30,60,15,7,2,9,200};

int partition(int l, int h)
{
	int pivot, i, j, temp;
	pivot = array[l];
	i = l;
	j = h;
	while(i < j)
	{
		do
		{
			i++;
		}while(array[i] <= pivot);
		do
		{
			j--;
		}while(array[j] > pivot);
		if(i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[l];
	array[l] = array[j];
	array[j] = temp;
	return j;
}

void quickSort(int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(l,h);
		quickSort(l,j);
		quickSort(j+1,h);
	}
}

int main(void)
{
	int l = 0, h = size;
	
	quickSort(l,h);
	
	return 0;
}
