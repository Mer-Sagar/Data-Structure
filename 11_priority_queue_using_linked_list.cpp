#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
}*new_node, *temp, *head;

void push()
{
    int data, priority;
    struct node *ptr, *preptr;
    printf("Enter data :  ");
    scanf("%d", &data);
    printf("Enter Priority :  ");
    scanf("%d", &priority);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    if(head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        return;
    }
    ptr = head;
    while(ptr != NULL && ptr->priority>priority)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr==head)
    {
        new_node->next = head;
        head = new_node;
        return;
    }
    preptr->next = new_node;
    new_node->next = ptr;
}

void pop()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("Stack Underflow");
        return;
    }
    ptr = head;
    head = head->next;
    printf("Popped Element: Data :  %d   Priority : %d\n", ptr->data, ptr->priority);
    free(ptr);
}

void peek()
{
    printf("Data :  %d   Priority : %d\n", head->data, head->priority);   
}

void show()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Stack Underflow");
    }
    ptr = head;
    while(ptr->next != NULL)
    {
        printf("Data :  %d   Priority : %d\n", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("Data :  %d   Priority : %d", ptr->data, ptr->priority);
}

int main()
{
    int op=0;
   
    printf("\n\n1 :  Push");
    printf("\n2 :  Pop");
    printf("\n3 :  Peek");
    printf("\n4 :  Show");
    printf("\n5 :  Exit");
    while(op!=5)
    {
        printf("\nEnter your option :  ");
        scanf("%d",&op);
        switch (op)
        {
            case 1 : push();
                break;

            case 2 : pop();
                break;
        
            case 3 : peek();
                break;

            case 4 : show();
                break;

            case 5 : printf("\nExiting!!!");
                break;

            default : printf("\nInvalid Input");
                break;
        }
    }
}
