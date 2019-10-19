#include<stdio.h>
#include<stdlib.h>

void insert_begin();
void insert_at_specified_node();
void append();
int  length_node();
void display();
void delete_begin();
void delete_specified_node();
void delete_last();

struct node
{
	int data;
	struct node *next;
};
struct node * root = NULL;

int main(void)
{

	int choice;
	while(1)
	{
		printf("1 : insert_begin\n2 : insert_at_specified_node\n3 : append\n4 : length_node\n5 : display\n6 : delete_begin\n7 : delete_specified_node\n8 : delete_last\n9 : quit\n");
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_begin();
				break;
			case 2:
				insert_at_specified_node();
				break;
			case 3:
				append();
				break;
			case 4:
				length_node();
				break;
			case 5:
				display();
				break;
			case 6:
				delete_begin();
				break;
			#if 0
			case 7:
				delete_specified_node();
				break;
			case 8:
				delete_last();
				break;
			#endif
			case 9:
				printf("Wrong option entered");
				exit(0);

	//reverse_list();
	//swap_two_nodes();
	//sort_list();
		}
	}
	
	return 0;
}

void display()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = root;
	printf("Display the created node ");
	if(temp == NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		printf("Inside node data display ");
		while(temp->next != NULL)
		{
			printf("%d--> ",temp->data);	
			temp = temp->next;
		}
		printf("%d--> ",temp->data);	
		printf("\n\n");	
	}

}
void delete_begin()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(root == NULL)
	{
		printf("No node in the list");
	}
	else
	{
		temp = root;
		root = temp->next;
		temp->next = NULL;	
	}

}
void insert_begin()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the node data : ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	
	if(root == NULL)
	{
		root = temp;	
	}
	else
	{

		temp->next = root;
	 	root = temp;	
	}
}
void insert_at_specified_node()
{
	struct node *temp, *p;
	int loc, len, i = 1;
	printf("Enter the location where node is to be insert : ");
	scanf("%d",&loc);
	len = length_node();
	if(loc > len)
	{
		printf("\nInvalid location : ");
		printf("%d\n",loc);
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the node data at specified location : ");
		scanf("%d",&temp->data);
		temp->next = NULL;
		p = root;
		while(i<loc)
		{
			i++;
			p = p->next;
		}
		temp->next = p->next;
	 	p->next = temp;	
	}
	

}
void append()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the node data for last node : ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *p;
		p = root;

		while(p->next != NULL)
		{
			p = p->next;	
		}		
		
		p->next = temp;	
	}	

}
	
int length_node()
{
	struct node *temp;
	int count = 0;
	
	temp = root;

	while(temp != NULL)
	{
		temp = temp->next;
		count ++;
	}
	printf("length of created node is : %d\n",count);
	return count;
}
