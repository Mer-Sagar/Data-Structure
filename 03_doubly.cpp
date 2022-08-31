#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head, *new_node;

void create()
{
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next =NULL;
    head = new_node;
}

void insert_at_beg()
{
    
    if (head==NULL)
    {
        create();
        return;
    }

    int data;
    struct node *ptr;
    ptr = head;
    printf("Enter the data : ");
    scanf("%d", &data);
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    head->prev= new_node;
    head = new_node;
}

void insert_at_end()
{
    if(head==NULL)
    {
        insert_at_beg();
        return;
    }

    struct node *ptr;
    ptr = head;
    int data;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    printf("Enter data :  ");
    scanf("%d", &data);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = ptr;
    new_node->next = NULL;
    ptr->next = new_node;
}

void insert_before()
{
    if(head==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    int before, data, flag=0;
    struct node *ptr;
    struct node * preptr;
    ptr = head;
    printf("Enter the node you want to enter before : ");
    scanf("%d", &before);
    if(head->data == before)
    {
        insert_at_beg();
        return;
    }
     
    while(ptr != NULL)
    {
        if(ptr->data == before)
        {
            flag=1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }

    if(flag==1)
    {
        printf("Enter data : ");
        scanf("%d", &data);
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = ptr;
        new_node->prev = preptr;
        preptr->next = new_node;
        ptr->prev = new_node;
    }
    else
    {
        printf("%d does not exist in the linked list", before);
    }
    
}

void insert_after()
{
    if(head==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    int after, data, flag=0;
    struct node *ptr;
    struct node *preptr;
    ptr = head;
    preptr = head;
    printf("Enter the node you want to enter after : ");
    scanf("%d", &after);
    if(head->data == after)
    {
        insert_at_end();
        return;
    }
     
    while(ptr != NULL)
    {
        if(ptr->data == after)
        {
            flag=1;
            break;
        }
        ptr = ptr->next;
    }

    if(flag)
    {
        printf("Enter data :  ");
        scanf("%d", &data);
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next = new_node;
    }
    else
    {
        printf("%d does not exist in the linked list", after);
    }
    
}

void delete_first()
{
    if(head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    struct node *ptr;
    ptr = head->next;
    ptr->prev = NULL;
    free(head);
    head = ptr;
}

void delete_last()
{
    if(head==NULL)
    {
        printf("Linked List is empty");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        return;
    }
    struct node *ptr;
    struct node *preptr;
    ptr = head;

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void delete_before()
{
    struct node *ptr;
    struct node *preptr;
    int val_search, flag;

    if(head==NULL)
    {
        printf("Empty LInked List");
    }
    printf("Enter the data you want to delete before : ");
    scanf("%d", &val_search);

    ptr = head;
    preptr = head;
    
    if(ptr->next->data == val_search)
    {
        delete_first();
        return;
    }
    
    while(ptr != NULL)
    {
        if(ptr->data == val_search)
        {
            flag = 1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if(ptr->next != NULL)
    {
        ptr->next->prev = preptr;
    }
    free(ptr);
}

void delete_after()
{
    struct node *ptr;
    struct node *preptr;
    int val_search, flag;
    if(head==NULL)
    {
        printf("Empty LInked List");
        return;
    }

    printf("Enter the data you want to delete after : ");
    scanf("%d", &val_search);

    if(head->data == val_search)
    {
        delete_first();
        return;
    }
    
    ptr = head;
    preptr = head;

    while(ptr != NULL)
    {
        if(preptr->data == val_search)
        {
            flag = 1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }

    if(!flag)
    {
        printf("%d not found in the linked list", val_search);
        return;
    }
    
    if(preptr->next == NULL)
    {
        printf("%d has no elements after to be deleted", val_search);
        return;
    }

    preptr->next = ptr->next;
    if(ptr->next != NULL)       //IF this condition is false that means ptr is on the last element;
    {
        ptr->next->prev = preptr; 
    }
    free(ptr);
}

void show()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d",ptr->data);
        printf(" --> ");
        ptr = ptr->next;
    }
    printf("Null");
}

int main()
{
    int op = 0;
    
        printf("\n\n1 : Insert at begining");
        printf("\n2 : Insert at end");
        printf("\n3 : Insert Before");
        printf("\n4 : Insert After");
        printf("\n5 : Delete First Node");
        printf("\n6 : Delete last Node");
        printf("\n7 : Delete before a given Node");
        printf("\n8 : Delete after a given Node");
        printf("\n9 : Show Linked List");
        printf("\n12 : Exit");
        while(op != 12)
        {
            printf("\nEnter your option : ");
            scanf("%d",&op);

            switch(op)
            {
                case 1: 
                        insert_at_beg();
                        break;
                    
                case 2: 
                        insert_at_end();
                        break;

                case 3:
                        insert_before();
                        break;

                case 4: 
                        insert_after();
                        break;

                case 5:
                        delete_first();
                        break;

                case 6:
                        delete_last();
                        break;
                
                case 7:
                        delete_before();
                        break;

                case 8:
                        delete_after();
                        break;
                
                case 9:
                        show();
                        break;

                case 12:
                        printf("Exiting!!!");
                        break;
                
                default:
                        printf("Invalid choice");

            }
    }
}