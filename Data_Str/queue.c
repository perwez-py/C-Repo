#include<stdio.h>
#include<stdlib.h>

#define SIZE 6
int queue[SIZE];
int front = 0, rear = 0;

void length()
{
	int i = 0;
	if(front == rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(i < rear)
		{
			i++;
		}
	}
	printf("Length of queue is : %d\n",i);
}

void traverse()
{
	int i;
	if(front == rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i = 0; i<rear; i++ )
		{
			printf("queued data %d\n",queue[i]);
		}	
	}
}

void delete()
{
	int i;
	if(front == rear)
	{
		printf("Queue is empty\n");	
	}
	else
	{
		printf("deleted element : %d\n",queue[front]);
		for(i = 0; i<rear-1; i++)
		{
			queue[i] = queue[i+1];
		}
		rear--;
	}

}

void insert(int element)
{
	if(rear == SIZE)
	{
		printf("Queue is full\n");
	}
	else
	{
		queue[rear] = element;
		printf("queued data %d\n",queue[rear]);	
		rear++;
	}
}

int main(void)
{
	int ch, element;
	while(1)
	{
		printf("1 : insert\n2 : delete\n3 : traverse\n4 : length\n5 : quit\n");
		printf("enter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : 
						printf("Enter the element in queue : ");
						scanf("%d",&element);
						insert(element);
						break;
			case 2 :
						delete();
						break;
			case 3 :
						traverse();
						break;
			case 4 :
						length();
						break;
			case 5 :
						exit(0);
			default :
						printf("Invalid choice entered\n");
		}
	}	
	
	return 0;
}
