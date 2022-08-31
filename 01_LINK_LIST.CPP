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
void insert_after();
void insert_before();
void display();
void delete_first();
void delete_last();
void delete_given();

int main()
{
	// clrscr();
	int choice;

	 printf("\n 1 : Create Link List  ");
	 printf("\n 2 : Insert at beging  ");
	 printf("\n 3 : Insert at End  ");
	 printf("\n 4 : Insert after given node  ");
	 printf("\n 5 : Insert before give node  ");
	 printf("\n 6 : Display  ");
	 printf("\n 7 : Delete first Node ");
	 printf("\n 8 : Delete Last Node ");
	 printf("\n 9 : Delete Given Node ");
	 printf("\n 0 : Exit ");

	while(choice!=0)
	{
	  printf("\nEnter Choice : ");
	  scanf("%d",&choice);

	  switch(choice)
	  {
		case 1: createNode();
			   break;

		case 2: insert_begin();
			   break;

		case 3: insert_end();
			   break;

		case 4: insert_after();
			   break;

		case 5: insert_before();
			   break;

		case 6: display();
			   break;

		case 7: delete_first();
			   break;

		case 8: delete_last();
			   break;

		case 9: delete_given();
			   break;

		case 0: exit(0);
			   break;

		default: printf("Enter valid input");
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

	if(start==NULL)    		//when link list empty
	{
	  new_node->next=NULL;
	  start=new_node;
	}
	else
	{
	  ptr=start;

	  while(ptr->next!=NULL)      //traverse the link list
	  {
	    ptr=ptr->next;
	  }

	  ptr->next=new_node;
	  new_node->next=NULL;
	}
}

void insert_begin()
{
	struct node  *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	new_node->next=start;

	start=new_node;

}
void insert_end()
{
	struct node *ptr, *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	new_node->next=NULL;

	ptr=start;

	while(ptr->next!=NULL)
	{
	  ptr=ptr->next;
	}
	ptr->next=new_node;

}
void insert_after()
{
	struct node *ptr, *preptr, *new_node;
	int search, flag=0;
	new_node= (struct node *)malloc(sizeof(struct node));

	printf("Enter Data : ");
	scanf("%d",&new_node->data);

	printf("Enter Data you want to store after : ");
	scanf("%d",&search);

	ptr=start;
	
	while(ptr != NULL)
	{
		if(ptr->data==search)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==1)
	{
		new_node->next=ptr->next;
		ptr->next = new_node;
	}
	else
	{
		printf("Value not found");
	}

}
void insert_before()
{
	struct node *ptr,*preptr, *new_node;
	int search, flag=0;
	new_node=(struct node *)malloc(sizeof(struct node));

	printf("Enter Data in new node:");
	scanf("%d",&new_node->data);

	printf("Find data you want to store before : ");
	scanf("%d",&search);

	ptr=start;
	preptr=start;

	while(ptr!=NULL)
	{
		if(ptr->data==search)
		{
		    flag=1;
		    break;
		}
		preptr=ptr;
		ptr=ptr->next;
	}
	if(flag==1)
	{
	   preptr->next=new_node;
	   new_node->next=ptr;
	}
	else
	{
		printf("\n Value Not Found");
	}

}
void delete_first()
{
	struct node *ptr;
	if(start==NULL)
	{
	    printf("\n Link List is Empty");
	}
	else
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
}
void delete_last()
{
	struct node *ptr,*preptr;
	if(start==NULL)
	{
	  printf("\n Link list is Empty ");
	}
	else
	{
		ptr=start;
		preptr=start;
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}

		preptr->next=NULL;
		free(ptr);

	}

}
void delete_given()
{
	struct node *ptr,*preptr;
	int search;

	printf("Enter Value you want to delete : ");
	scanf("%d",&search);

	ptr=start;

	if(ptr->data==search)
	{
		delete_first();
	}
	else
	{
		while(ptr->data!=search)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
}

void display()
{
	struct node *ptr;

	if(start==NULL)       // NULL on first position that means list empty
	{
		printf("List Is Empty");
	}
	else
	{       ptr=start;

		while(ptr!=NULL)
		{
		 printf("\t %d", ptr->data);
		 ptr=ptr->next;
		}
	}
}