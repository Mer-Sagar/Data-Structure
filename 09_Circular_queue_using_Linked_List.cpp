#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*new_node, *temp, *head, *tail;



void enqueue()
{
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data :  ");
    scanf("%d",&data);
    new_node->data = data;
    
    if(head==NULL)
    {
        new_node->next = new_node;
        head = new_node;
        tail = new_node;
    }
    else
    {
        int data;
        temp = head;
        while(temp->next != head)  //Traversing to the end node
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        tail = new_node;
    }
}

void dequeue()
{
    int data;
    if(head==NULL)
    {
        printf("Queue is empty");
        return;
    }
    data = head->data;
    printf("Dequeued element :  %d", data);
    if(head->next == head)
    {
        free(head);
        tail = NULL;
        head = NULL;
        return;
    }
    temp = head->next;
    free(head);
    head = temp;
    tail->next = head;
}

void show()
{
    if(head==NULL)
    {
        printf("Queue is empty");
        return;
    }
    temp = head;
    
    do
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("NULL");
}

int main()
{
    int op=0;
    
    printf("\n\n1 :  Enqueue");
    printf("\n2 :  dequeue");
    printf("\n3 :  Show");
    printf("\n4 :  Exit");

    while(op!=4)
    {
        printf("\nEnter your option :  ");
        scanf("%d",&op);
        switch (op)
        {
            case 1 : enqueue();
                break;

            case 2 : dequeue();
                break;
        
            case 3 : show();
                break;

            case 4 : printf("\nExiting!!!");
                break;

            default : printf("\nInvalid Input");
                break;
        }
    }
}
