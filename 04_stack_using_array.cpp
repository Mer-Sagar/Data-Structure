#include<stdio.h>
#include<conio.h>

int stack[5];
int max = 5;
int top=-1;

void push()
{
    int item;
    if(top>=max-1)
    {
        printf("\nStack overflow");
        return;
    }
    printf("Enter the item :  ");
    scanf("%d",&item);
    stack[++top] = item;
}

void pop()
{
    if(top<0)
    {
        printf("\nStack underflow");
        return;
    }
    printf("\nThe popped item is %d", stack[top--]);
}

void peek()
{
    if(top<0)
    {
        printf("\nStack underflow");
        return;
    }
    printf("Item at top is :  %d", stack[top]);
}

void display()
{
    int i;
    if(top<0)
    {
        printf("\nStack underflow");
        return;
    }
    printf("Stack items are : ");
    for(i=0;i<=top;i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int op=0;
    
    printf("\n1 : Push");
    printf("\n2 : Pop");
    printf("\n3 : Peek");
    printf("\n4 : Display");
    printf("\n5 : Exit");

    while(op!=5)
    {
        
        printf("\nEnter your option :  ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: push();
                    break;
            
            case 2: pop();
                    break;
                
            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: printf("Exiting the program!!!");
                    break;

            default: printf("Enter valid option");
                    break;
        }
    }
}
