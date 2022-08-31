#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>

float stack[100];
int max = 100;
int top=-1;

void push(int item)
{
    stack[++top] = item;
}

float pop()
{
    if(top<0)
    {
        printf("\nStack underflow");
        return INT_MIN;
    }
    return stack[top--];
}

void evaluate_postfix(char* exp)
{
    int i;
    int len = strlen(exp);

    for(i=0;i<len;i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            float a = pop();
            float b = pop();
            if(a == INT_MIN || b == INT_MIN)
            {
                printf("Wrong expression!!!");
                return;
            }
            switch (exp[i])
            {
                case '+': 
                            push(b + a);
                            break;
                case '-':   push(b - a);
                            break;
                case '*':   push(b * a);
                            break;
                case '/':   push(b / a);
                            break;
            }
        }
    }
    printf("Evaluation :  %.2f", pop());
}

int main()
{
    char exp[100];
    printf("Enter the expression :  ");
    scanf("%s",&exp);
    evaluate_postfix(exp);
    getch();
}
