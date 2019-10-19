#include<stdio.h>
#include<stdlib.h>

int count = 0;
struct node
{
	struct node *L;
	struct node *R;
	int data;
};

struct node *root = NULL;

void append();
void display();
void add_begin();
void delete_begin();
void delete_intermediate();
void delete_last();
void add_last();
void middle();
int  length();
void swap();
void reverse();


int main(void)
{
	int choice;
	while(1)
	{
		printf("\n\n1 : APPEND\n2 : ADD_BEGIN\n3 : DELETE_BEGIN\n4 : ADD_LAST\n5 : MIDDLE\n6 : LENGTH\n7 : SWAP\n8 : REVERSE\n9 : DISPLAY\n10 : QUIT\n11 : DELETE_INTERMEDIATE\n12 : DELETE_LAST\n\n");

		printf("Enter the choice which is going to perform : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				append();
				break;
			case 9:
				display();
				break;
			case 6:
				length();
				break;
			case 2:
				add_begin();
				break;
			case 4:
				add_last();
				break;
			case 5:
				middle();
				break;
			case 3:
				delete_begin();
				break;
			case 11:
				delete_intermediate();
				break;
			case 12:
				delete_last();
				break;
			case 7:
				swap();
				break;
			case 8:
				reverse();
				break;
		#if 0
		case 10:
			exit(0);
			break;
		#endif
			
		}
	}
	return 1;
}

void delete_begin()
{
	struct node *temp;
	temp = root;
	if(temp->L == NULL)
	{
		temp->R->L = NULL;
		root = temp->R;
		temp->R = NULL;
	}
}
void delete_last()
{
	struct node *temp;
	temp = root;
	if(temp->R == NULL)
	{
		temp->L->R = NULL;
	}
}
void delete_intermediate()
{
	struct node *p;
	int len,loc,i = 1;
	printf("\nEnter the node location which is going to delete : ");
	scanf("%d",&loc);
	len = length();
	if(loc > len)
	{
		printf("Invalid location");
	}
	else
	{
		p = root;
		while(i<loc)
		{
			p = p->R;
			i++;
		}
		p->L->R = p->R;
		p->R->L = p->L;
		free(p);
	}
}
void add_begin()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the node element at begin : ");
	scanf("%d",&temp->data);
	temp->L = NULL;
	temp->R = NULL;
	if(root == NULL)
	{
		root = temp;
	}	
	else
	{
		temp->R = root;
		root->L = temp;
		root = temp;	
	}
}
void add_last()
{
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the node element at last : ");
	scanf("%d",&temp->data);
	temp->L = NULL;
	p = root;
	
	while(p->R != NULL)
		p = p->R;

	temp->L = p;
	p->R = temp;
	temp->R = NULL;
}
void reverse()
{
	int len,i = 0;
	struct node *temp,*p,*q;
	//temp = (struct node*)malloc(sizeof(struct node));
	temp = p = q = root;

	while(i<count-1)
	{
		temp->data = p->data;
		p->data = q->data;
		q->data	= temp->data;	
		i++;
		count--;
		p = p->R;
		q = q->L;
	}
}
void middle()
{
	struct node *temp,*p;
	int loc,len,i = 1;
	printf("\nEnter the node element : ");
	scanf("%d",&temp->data);
	printf("\nEnter the location where node is to be added : ");
	scanf("%d",&loc);
	temp->L = NULL;
	temp->R = NULL;
	len = length();
	if(loc > len)
	{
		printf("Invalid location");
	}
	else
	{
		p = root;
		while(i<loc)
		{
			p = p->R;
			i++;
		}
		temp->R = p->R;
		p->R->L = temp;
		temp->L = p;
		p->R = temp;
	}
		
}
void swap()
{
	struct node *p,*q,*r;
	int loc,i = 1;
	printf("\nEnter the location where node is to be swap : ");
	scanf("%d",&loc);
	while(i<loc-1)
	{
		p = p->R;
		i++;
	}
	
	q = p->R;
	r = q->R;
	q->R = r->R;
	r->R = q;
	q->R->L = q;
	r->L = p;
	q->L = r;
	p->R = r;
}

void append()
{
	struct node *temp;
 	temp = (struct node*)malloc(sizeof(struct node));	

	printf("\nEnter the node element : ");
	scanf("%d",&temp->data);
	temp->L = NULL;
	temp->R = NULL;

	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *p;
		p = root;
		while(p->R != NULL)
			p = p->R;	
		p->R = temp;
		temp->L = p;
	}
}
void display()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp = root;
	printf("Created node\t");
	while(temp->R != NULL)
	{
		printf("%d-> ",temp->data);
		temp = temp->R;
	}
	printf("%d->",temp->data);	

}

int length()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = root;
	while(temp != NULL)
	{
		temp = temp->R;
		count++;
	}
	printf("length of created double linklist node : %d",count);
	return count;
}
