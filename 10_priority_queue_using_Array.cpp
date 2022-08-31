#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

int count = 0;

struct item
{
    int data;
    int priority;
};

struct item pqueue[SIZE];

void enqueue()
{
    int data;
    int priority;
    if(SIZE == count)
    {
        printf("Overflow");
        return;
    }
    printf("Enter data :  ");
    scanf("%d", &data);
    printf("Enter Priority :  ");
    scanf("%d", &priority);
    pqueue[count].data = data;
    pqueue[count].priority = priority;
    count++;
}

int peek()
{
    int i;
    int highestPriority = INT_MIN;
    int index = -1;

    for(i=0;i<count;i++)
    {
        if(highestPriority==pqueue[i].priority && index > -1 &&  pqueue[index].data < pqueue[i].data)
        {
            highestPriority = pqueue[i].priority;
            index = i;
        }
        else if(highestPriority<pqueue[i].priority)
        {
            highestPriority = pqueue[i].priority;
            index = i;
        }
    }

    return index;
}

void dequeue()
{
    int index = peek();
    if(index == -1) 
    {
        printf("Underflow");
        return;
    }
    printf("\nDequeued element :  %d",pqueue[index].data);
    printf("\nDequeued element priority :  %d",pqueue[index].priority);
    for(int i = index;i<count;i++)
    {
        pqueue[i] = pqueue[i+1];
    }
    count--;
}

void showPeek()
{
    int index = peek();
    if(index==-1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\nData :  %d", pqueue[index].data);
    printf("\nPriority :  %d", pqueue[index].priority);
}

void show()
{
    int i=0;
    printf("Count :  %d", count);
    for(i=0;i<count;i++)
    {
        printf("\nitem at i[%d] priority is  %d  :- %d  ", i,  pqueue[i].priority, pqueue[i].data);
    }
}

int main()
{
    int op = 0;
    int data;
    
    printf("\n\n1 :  Enqueue");
    printf("\n2 :  Dequeue");
    printf("\n3 :  Peek");
    printf("\n4 :  Show");
    printf("\n5 : Exit");

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
                    showPeek();
                    break;

            case 4:
                    show();
                    break;

            case 5:
                    printf("Exiting!!!");
                    break;
            
            default:
                    printf("Invalid Input");
                    break;
        }
    }
}

