#include<stdio.h>
#include<stdbool.h>

#if 0
/*Compute the sign of interger*/
int main()
{
	int sign = 0;
	int data = 0;

	printf("Enter the data which is going to check : ");
	scanf("%d",&data);
	
	sign = (data > 0) - (data < 0);
	if(sign == 1)
		printf("Number is positive number\n");
	else if(sign == -1)
		printf("Number is negative number\n");
	else
		printf("Number is zero\n");

	return 0;
}
/*Compute the sign of interger*/
#endif

#if 0

/*Detect two interger have opposite sign*/

bool checkOppsBit(int a, int b)
{
	bool bRetVal = 0;

	bRetVal = ((a ^ b) < 0);
	return bRetVal;

}

int main()
{
	int a = 0, b = 0;
	bool retVal;
	printf("Enter the value of a = ");
	scanf("%d",&a);
	printf("Enter the value of b = ");
	scanf("%d",&b);
	
	retVal = checkOppsBit(a,b);

	if(true == retVal)
		printf("Integer have the opposite sign\n");
	else
		printf("Integer have the same sign\n");

	return 0;
}
/*Detect two interger have opposite sign*/
#endif


#if 0
/*Check an integer is a power of 2*/
int main()
{
	int flag = 0;
	int data = 0;

	printf("Enter the integer : ");	
	scanf("%d",&data);

	flag = (data != 0) && !(data & (data -1));

	if (flag == 1)
		printf("Number is a power of 2\n");
	else
		printf("Enter number not power of 2\n");

	return 0;
}
/*Check an integer is a power of 2*/
#endif

#if 0
/*How to set particular bit in c*/
int main()
{
	int data = 0x00;
	int pos = 0;

	printf("Enter the pos which is going to set : ");
	scanf("%d",&pos);

	data = data | (1 << pos);

	printf("Value after set bit is %d \n",data);
	return 0;
}
/*How to set particular bit in c*/
#endif


#if 0
/*How to clear particular bit in c*/
int main()
{
	int data = 0xff;
	int pos = 0;

	printf("Enter the bit position to be clear : ");
	scanf("%d",&pos);

	data = data & ~(1 << pos);

	printf("Value after position bit is clear : %d\n",data);

	return 0;
}
/*How to clear particular bit in c*/
#endif

#if 0
/*How to check particular bit is set in c*/
int main()
{
	int data = 0;
	int pos = 0;

	printf("Enter the number : ");
	scanf("%d",&data);
	printf("Enter the bit position which is going to check ");
	scanf("%d",&pos);

	data = data & (1 << pos);

	if(data)
		printf("Bit is set\n");
	else
		printf("Bit is not set\n");

	return 0;

}
/*How to check particular bit is set in c*/
#endif

#if 0
int main()
{
	int data = 0;
	int pos = 0;

	printf("Enter the value : ");
	scanf("%d",&data);
	printf("Enter the bit position which is to toggle : ");
	scanf("%d",&pos);

	data = data ^ (1 << pos);

	printf("Value of data after the particular bit was toggle : 0x%x\n",data);

	return 0;
}
#endif

#if 0
/*Count set bits of an integer*/
int main()
{
	int data = 0;
	int countBits = 0;

	printf("Enter the value : ");
	scanf("%d",&data);

	while(data)
	{
		countBits = countBits + (data & 1);
		data = data >> 1;
	}
	
	printf("Count bit of enter data : %d\n",countBits);

	return 0;
}
/*Count set bits of an integer*/
#endif

#if 0
void swapTwoNum(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;

	printf("value of a = %d\nvalue of b = %d\n",*a,*b);

}

int main()
{
	int a = 10;
	int b = 20;

	swapTwoNum(&a,&b);

	return 0;
}
#endif

#if 0
/*Clear all bits from msb to ith bits*/
int main()
{
	unsigned int mask = 0;
	unsigned int i = 2;
	unsigned int data = 16;

	mask = 1 << (i + 1);
	mask = mask - 1;

	data = data & mask;

	printf("Value after all bits clear from msb is : %d\n",data);

	return 0;
}
/*Clear all bits from msb to ith bits*/
#endif


#if 0
/*Clear all the bits from lsb to ith bits*/
int main()
{
	unsigned int mask = 0;
	unsigned int i = 2;
	unsigned int data = 11;

	mask = 1 << (i + 1);
	mask = mask - 1;
	mask = ~mask;

	data = data & mask;

	printf("Value after all bits clear from lsb is : %d\n",data);

	return 0;
}
/*Clear all the bits from lsb to ith bits*/
#endif

#if 0
int main()
{
	int data = 15;
	printf("%d",data);

	data = data << 1;

	printf(" multiply by 2 : %d\n",data);

	int dData = 8;
	printf("%d",dData);

	dData = dData >> 1;
	printf(" Divide by 2 : %d\n",dData);

	return 0;
}
#endif

#if 0
/*Nibble swap*/
int main()
{
	unsigned char data = 0x8;

	data = ((data & 0x0f) << 4 | (data & 0xf0) >> 4);

	printf("After nibble swap from a byte %d\n",data);

	return 0;
}
/*Nibble swap*/
#endif

#if 0
/*swap bytes of 32 bits integer*/
#define SWAP_BYTES(value) ((value & 0x000000ff) << 24)\
			 										|((value & 0x0000ff00) << 8)\
													|((value & 0x00ff0000) >> 8)\
													|((value & 0xff000000) >> 24)													


int main()
{
	unsigned int value = 0x00112233;
	unsigned int result = 0;

	result = SWAP_BYTES(value);

	printf("after swap bytes of 32bits integer : 0x%x\n",result);

	return 0;
}
/*swap bytes of 32 bits integer*/
#endif


#if 0
int main()
{
	int data = 10;

	data = (data & 0xAAAAAAAA) >> 1 | (data & 0x55555555) << 1;

	printf("%d\n",data);

	return 0;
}
#endif


#if 0
/*Count number of flipped bits */
int countFlippedBits(int a, int b)
{
	int setBits, count;
	setBits = a ^ b;

	while(setBits)
	{
		count = count + (setBits & 1);
		setBits = setBits >> 1;
	}

	return count;
}

int main()
{
	int a = 30;
	int b = 16;

	int flippedBits = 0;

	flippedBits = countFlippedBits(a,b);
	
	printf("Number of flipped bits is : %d\n",flippedBits);

	return 0;
}
/*Count number of flipped bits */
#endif

/*Find the number that appers once*/

#if 0
int NumAppearsOnce(int arr[], int asize)
{
	int result = 0, i;

	result = arr[0];
	for(i = 1; i < asize; i++ )
	{
		result = result ^ arr[i];
	}

	return result;
}

int main()
{
	int arr[10] = {1,3,5,2,5,3,7,2,1};
	int numOut, asize = 0;

	asize = sizeof(arr)/sizeof(int);

	numOut = NumAppearsOnce(arr,asize);
	
	printf("Unique number from the array list : %d\n",numOut);

	return 0;
}

/*Find the number that appers once*/
#endif

int main()
{
	unsigned int data = 0x65535322;
		


}
