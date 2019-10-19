#include<stdio.h>
#include<malloc.h>

#if 0
/*size of array varible*/
int main()
{
	int arr[17];
	
	//printf("size of array : %d\n",*(&arr + 1) - arr);
	//printf("size of array : %d\n",(&arr)[1] - arr);
	//printf("size of array : %d\n",sizeof(arr)/sizeof(arr[0]));
	printf("size of array : %d\n",sizeof(arr)/sizeof(int));
	return 0;
}
/*size of array varible*/
#endif

#if 0
/*1D array using dynamic memory allocation*/

int main()
{
	int *parr = NULL;
	int arrBlockSize = 0, i;

	printf("Enter the array block size : ");
	scanf("%d",&arrBlockSize);

	parr = (int *)malloc(arrBlockSize * sizeof(int));

	if(parr == NULL)
		return 1;

	for(i = 0; i<arrBlockSize; i++)
	{
		parr[i] = i;
	}

	for(i = 0; i<arrBlockSize; i++)
	{
		printf("parr[%d] = %d\n",i,parr[i]);	
	}

	return 0;
}
/*1D array using dynamic memory allocation*/
#endif

int main()
{
	int **parr = NULL;
	int rowSize,columnSize,row,column;

	printf("Enter the row size : ");
	scanf("%d",&rowSize);
	printf("Enter the column size : ");
	scanf("%d",&columnSize);

	parr = (int **)malloc(rowSize * sizeof(int *));

	if(parr == NULL)
		return 1;

	for(row = 0; row < rowSize; row++)
	{
		parr[row] = (int *)malloc(columnSize * sizeof(int));
		if(parr[row] == NULL)
			return 1;
	}

	for(row = 0; row < rowSize; row++)
	{
		for(column = 0; column < columnSize; column++)
		{
			parr[row][column] = 3;
		}
	}

	for(row = 0; row < rowSize; row++)
	{
		for(column = 0; column < columnSize; column++)
		{
			printf("parr[%d][%d] = %d\n",row,column, parr[row][column]);
		}
	}
	
	for(row = 0; row < rowSize; row++)
	{
		free(parr[row]);
	}

	free(parr);

	return 0;
}
