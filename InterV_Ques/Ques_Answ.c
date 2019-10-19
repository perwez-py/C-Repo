		#if 0
		Swap two nibbles in byte(Bit wise)
		Set bits(Bit wise)
		Count set bits in it(bit wise)
		Multiply two polynomials(Mathematics)
		Swap two numbers(Mathematics)
		Count numbers divisible by M(Mathematics)
		Reverse words in a given string(string)
		Factorial of large number()
		Permutations of a given string(string)
		Longest palindrome in a string(string)
		Sum of all prime number between 1 to N(Mathematics)
		Smallest positive missing number(Array)
		Remove duplicate elemets from sorted array(arrays)
		#endif

#include<stdio.h>
#include<string.h>

#if 0
unsigned char swapNibbles(unsigned char a)
{
	return (( a & 0x0f) <<4 | ( a & 0xf0) >>4);
}

int main()
{
	unsigned char x = 100;
	printf("%u\n",swapNibbles(x));	
	return 0;
}
#endif

#if 0
int main()
{
	unsigned int byte;
	unsigned int bit_pos = 3;
	unsigned int tempByte = 0x01;

	byte = ( tempByte << bit_pos);

	printf("0x%x[%d]\n",byte,byte);

	return 0;

}
#endif

#if 0
int count = 0;
unsigned int countBits( unsigned int a)
{
	while(a)
	{
		count += a & 1;
		a = a >> 1;	
	}
}
int main()
{
	unsigned int x = 11;
	printf("%d\n",countBits(x));

return 0;
}
#endif

#if 0
void swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
	printf("x = %d, y = %d \n",*x,*y);
}

int main()
{
	int a = 10, b = 20, c;
	
	//swap(&a,&b);

#if 0
************
	a = a + b;
	b = a - b;
	a = a - b;
************
#endif

	c = a;
	a = b;
	b = c;

	printf("a = %d, b = %d \n",a,b);

	return 0;
}
#endif

#if 0
void reverse(unsigned char xyz[])
{
	printf("reverse function\n");	
	unsigned char abc[10];
	int j,i,count = 0;
	printf("before reverse string : %s\n",xyz);	
	
	while(xyz[count] != '\0')
		count++;

	j = count - 1;
	
	for(i = 0; i<count; i++)
	{
		abc[i] = xyz[j];
		j--;
	}

	abc[i] = '\0';

	printf("After reverse string : %s\n",abc);	

}

int main()
{
	unsigned char str[10];

	printf("Enter the string which you want reverse : ");
	scanf("%s",str);

	reverse(str);

	return 0;
}
#endif


#if 0
int str_len(unsigned char *ch)
{
	int i = 0;
	while(ch[i] != '\0')
		i++;
	printf("length of string : %d\n",i);
	return i;
}

void reverse(unsigned char *s)
{
	unsigned char *begin, *end, temp;
	int  len = 0,c;
	len = str_len(s);

	begin = s;
	end = s;

	for(c = 0; c < len -1; c++)
		end++;

	for(c = 0; c < len/2; c++)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;

		begin++;
		end--;
	}

}

int main()
{
	unsigned char s[] = "hammad";
	//unsigned char s[10];
	//printf("Enter the string : ");
	//scanf("%s",s);
	reverse(s);
	printf("After reverse string <<< %s >>>\n",s);

	return 0;
}
#endif


int main()
{
	int i,j,prime_flag, sum = 0,start = 2,end = 100;

	for(i = start; i <= end; i++)
	{
		prime_flag = 1;

		for(j = 2; j <= i/2; j++)
		{
			if(i%j == 0)
			{
				prime_flag = 0;
				break;
			}
		}
		
		if(prime_flag == 1)
		{
			sum += i;
		}	
	
	}

	printf("sum of prime number is : %d\n",sum);
	
	return 0;
}
