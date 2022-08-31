#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;

void createNode();
void insert_begin();
void insert_end();
void display();
void delete_first();
void delete_last();

int main()
{
	// clrscr();
	int choice;

	printf("\n 1 : Create Link List ");
	printf("\n 2 : Insert at beging ");
	printf("\n 3 : Insert at End ");
	printf("\n 4 : Delete first node ");
	printf("\n 5 : Delete last node ");
	printf("\n 6 : Display ");
	printf("\n 0 : Exit ");

	while(choice!=0)
	{
		printf("\n Enter Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: createNode();
				    break;

			case 2: insert_begin();
				    break;

			case 3: insert_end();
				    break;

			case 4: delete_first();
				    break;

			case 5: delete_last();
				    break;

			case 6: display();
				    break;

			case 0: exit(0);
				    break;
			default: printf("Enter valid input... ");
		}
	}
	getch();
}
void createNode()
{
	struct node *new_node, *ptr;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	if(start==NULL)
	{
	   new_node->next = new_node;
	   start=new_node;
	}
	else
	{
		ptr = start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->next=start;
	}
}
void insert_begin()
{
	struct node *ptr, *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	ptr=start;

	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;

	start=new_node;	
}
void insert_end()
{
	struct node *ptr, *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	ptr=start;

	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;



}
void delete_first()
{
	struct node *ptr;

	if(start==NULL)
	{
		printf("Link List Underflow ");
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}

		ptr->next=start->next;
		free(start);

		start=ptr->next;
	}
}
void delete_last()
{
	struct node *ptr, *preptr;

	if(start==NULL)
	{
		printf("Link List is UNDERFLOW");
	}
	else
	{
		ptr=start;
		preptr=start;

		while(ptr->next!=start)
		{
		    preptr=ptr;
		    ptr=ptr->next;
		}
		preptr->next=start;
		free(ptr);
	}

}

void display()
{
	struct node *ptr;

	ptr=start;

	while(ptr->next!=start)
	{
		printf("\t %d",ptr->data);
	    ptr=ptr->next;
	}
	printf("\t %d", ptr->data);
}