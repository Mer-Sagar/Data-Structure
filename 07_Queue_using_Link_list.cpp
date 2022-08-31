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

    if(head==NULL)
    {
        new_node->data = data;
        new_node->next=NULL;
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)  //Traversing to the end node
        {
            temp = temp->next;
        }
        new_node->data = data;
        new_node->next = NULL;
        temp->next = new_node; 
    }
}

void dequeue()
{
    if(head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    temp = head->next;
    free(head);
    head = temp;
}

void show()
{
    if(head==NULL)
    {
        printf("Stack is empty");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void show_front()
{
    if(head==NULL)
    {
        printf("Stack is empty");
        return;
    }
    printf("Front :  %d", head->data);
}

int main()
{
    int op = 0;
    
    printf("\n\n1 :  Enqueue");
    printf("\n2 :  Dequeue");
    printf("\n3 :  Show front");
    printf("\n4 :  Show");
    printf("\n5 :  Exit");

    while(op != 5)
    {
        printf("\nEnter your option :  ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: 
                    enqueue();
                    break;
                
            case 2: 
                    dequeue();
                    break;

            case 3:
                    show_front();
                    break;

            case 4: 
                    show();
                    break;
            
            case 5: 
                    printf("Exiting the program");
                    break;

            default: printf("Enter valid option");
                    break;
        }
    }

}
