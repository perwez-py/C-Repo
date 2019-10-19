#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * root = NULL;

void insersion()
{
	struct node *t, *p;
	int data;
	t = (struct node*)malloc(sizeof(struct node));
	printf("Enter the node element in BST : ");
	scanf("%d",&data);
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	p = root;
	if(root == NULL)
	{
		root = t;
	}
	else
	{
		struct node *curr;
		curr = root;
		while(curr)
		{
			p = curr;
			if(t->data > curr->data)
			{
				curr = curr->right;		
			}	
			else
			{
				curr = curr->left;
			}
		}
		if(t->data > p->data)
		{
			p->right = t;		
		}
		else
		{
			p->left = t;
		}
	}
}

void traverse()
{
	

}

int main(void)
{
	int ch;
	printf("------------------BINARY SEARCH TREE------------------\n");
	while(1)
	{
		printf("1 : insersion\n2 : traverse\n3 : quit\n");
		printf("Enter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				insersion();
				break;
			case 2 : 
				traverse();
				break;
			case 3 : 
				exit(0);
			default :
				printf("Invalid choice entered\n");
		}
	}
	return 0;
}
