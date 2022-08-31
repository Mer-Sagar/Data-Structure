#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*new_node, *temp, *head;

// void create()
// {
//     int data;
//     new_node = (struct node*)malloc(sizeof(struct node));
//     printf("Enter the data :  ");
//     scanf("%d",&data);
//     new_node->data = data;
//     new_node->next=NULL;
//     head = new_node;
// }

void push()
{
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data :  ");
    scanf("%d",&data);
    new_node->data = data;

    if(head==NULL)
    {
        new_node->next=NULL;
        head = new_node;
    }
    else
    {    
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
}

void pop()
{
    int data;
    if(head==NULL)
    {
        printf("Stack is underflow");
        return;
    }
    printf("Deleted element :  %d", head->data);
    temp = head->next;
    data = head->data;
    free(head);
    head = temp;
}

void peek()
{
    if(head==NULL)
    {
        printf("Stack is underflow");
        return;
    }
    printf("Peeked element :  %d", head->data);
}

void show()
{
    if(head==NULL)
    {
        printf("Stack underflow");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
