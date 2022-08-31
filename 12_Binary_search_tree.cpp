#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
}*root, *new_node;

void preorder(struct Node* node)
{
    if(node == NULL) return;
    printf("%d " ,node->data);
    preorder(node->leftChild);
    preorder(node->rightChild);
}

void postorder(struct Node* node)
{
    if(node == NULL) return;
    postorder(node->leftChild);
    postorder(node->rightChild);
    printf("%d " ,node->data);
}

void inorder(struct Node* node)
{
    if(node == NULL) return;
    inorder(node->leftChild);
    printf("%d " ,node->data);
    inorder(node->rightChild);
    
}

void find_max()
{
    if(root == NULL)
    {
        printf("Tree is empty");
    }
    new_node = root;
    while(new_node->rightChild != NULL)
    {
        new_node = new_node->rightChild;
    }
    printf("Maximum :  %d", new_node->data);
}

void find_min()
{
    if(root == NULL)
    {
        printf("Tree is empty");
    }

    new_node = root;

    while(new_node->leftChild != NULL)
    {
        new_node = new_node->leftChild;
    }

    printf("Minimum :  %d", new_node->data);
}

struct Node* createNewNode(int data)
{
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    if(root == NULL)
    {
        root = new_node;   
        return root;
    }
    return new_node;
}

struct Node* insert(struct Node* node, int data)
{
    if (node==NULL)
         return createNewNode(data);

    if(data < node->data)
        node->leftChild = insert(node->leftChild, data);
    
    else if(data > node->data)
        node->rightChild = insert(node->rightChild, data);

    return node;
    
}

void search(int data)
{
    int flag = 0;
    new_node = root;
    while(new_node != NULL)
    {
        if(data == new_node->data)
        {
           flag=1;
           break;
        }
        else if(data < new_node->data)
        {
            new_node = new_node->leftChild;
        }
        else
        {
            new_node = new_node->rightChild;
        }
    }

    if(flag == 0) printf("%d does not exist in the tree", data);
    else printf("%d exist in the tree", data);
}

int main()
{
    int op = 0;
    int data;
    
    printf("\n\n1 :  Insert");
    printf("\n2 :  Delete");
    printf("\n3 :  Search");
    printf("\n4 :  Prefix");
    printf("\n5 :  Postfix");
    printf("\n6 :  Infix");
    printf("\n7 :  Maximum");
    printf("\n8 :  Minimum");

    while(op != 12)
    {    
        printf("\nEnter your choice :  ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: 
                    printf("Enter the data :  ");
                    scanf("%d", &data);
                    insert(root, data);
                    break;
                
                
            case 2:
                    printf("Enter the data :  ");
                    scanf("%d", &data);
                    break;

            case 3:
                    printf("Enter the data :  ");
                    scanf("%d", &data);
                    search(data);
                    break;

            case 4:
                    preorder(root);
                    break;
            
            case 5:
                    postorder(root);
                    break;

            case 6:
                    inorder(root);
                    break;

            case 7:
                    find_max();
                    break;

            case 8:
                    find_min();
                    break;

            case 12:
                    printf("Exiting!!!");
                    break;

            default:
                    printf("Please enter an valid input");
                    break;
        }
    }
}
