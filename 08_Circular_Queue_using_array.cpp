#include<stdio.h>
#include<conio.h>
int size=5;
int queue[5];
int front = -1;
int rear = -1;

void enqueue()
{
    int val;
    // Normal condition was rear == size-1 we added front == 0 with it
    //another condition is if rear is just behind front 
    if(front==rear+1 || (front==0 && rear == size-1))
    {
        printf("Queue is full");
        return;
    }

    if(rear == -1 & front == -1 )
    {
        front += 1;
    }
    
    printf("Enter the value to insert :  ");
    scanf("%d", &val);
    //wher rear becomes 4  :  (4+1) % 5 will not happen because the full condition is fulfiled
    rear = (rear + 1) % size;
    queue[rear] = val;
}

void dequeue()
{

    if(front==-1 && rear==-1)    
    {
        printf("Queue is empty");
        return;
    }

    printf("\nDequeued item is :  %d", queue[front]);

    //whenever the last element is removed
    if(front == rear)
    {
        front=-1;
        rear=-1;
    }
    // increment of front
    else front = (front + 1) % size;
}

void show()
{   
    int i = 0;
    if(rear==-1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Values in queue are :  ");

    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\nFront :  %d", front);
    printf("\nRear :  %d", rear);
}

void show_front()
{
    printf("Front :  %d", front);
    if(front!=-1) printf("\nValue at Front :  %d", queue[front]);
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
