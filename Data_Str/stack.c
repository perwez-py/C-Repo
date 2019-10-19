#include<stdio.h>
#include<stdlib.h>

#define CONTAINER 5
int top = -1;
int stack[CONTAINER];


int isfull()
{
	if(top == CONTAINER-1)
	{
		return 1;
	}
	else
		return 0;
}

void push(int data)
{
	if(isfull())
	{
		printf("Stack is full\n");
	}
	else
	{
		top ++;
		stack[top] = data;	
		printf("pushed data %d\n",data);
	}
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
		return 0;
}


int pop()
{
	int temp_element;
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		temp_element = stack[top--];
	}
	return temp_element;
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
		return stack[top];
}

void traverse()
{
	int i;
	if(isEmpty())
	{
		printf("Stack is Empty\n");
	}
	else
	{
		for(i = 0; i<=top; i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}

int length()
{
	int i = 0;
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		while(i <= top)
		{
			i++;
		}
	}

	return i;
}

int main(void)
{
	int data, ch;
	while(1)
	{
		printf("1 : push\n2 : pop\n3 : peek\n4 : traverse\n5 : quit\n6 : length\n");
		printf("Enter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
					printf("Enter the element to be push : ");
					scanf("%d",&data);  
					push(data);
					break;
			case 2 : 
					data = pop();
					printf("pop data from the stack : %d\n",data);
					break;
			case 3 : 
					data = peek();
					printf("peek data from the stack : %d\n",data);
					break;
			case 4 : 
					traverse();
					break;
			case 5 : 
					exit(0);
			case 6 :
					data = length();
					printf("length of stack %d\n",data);
					break;
			default : printf("Incorrect options entered...\n");
		}
	}
	
	return 0;

}
