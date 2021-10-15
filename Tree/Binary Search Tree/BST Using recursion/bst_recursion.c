

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode()
{
    struct node *newnode = NULL;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (!(newnode == NULL))
    {
        int data;
        printf("Enter a data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else
    {
        printf("Node not created.\n");
    }
    return newnode;
}

void recuusiveBST(struct node *curuentRoot, struct node *newnode)
{
    struct node *temp = curuentRoot;
    if (temp->data < newnode->data)
    {
        if (temp->right == NULL)
        {
            temp->right = newnode;
        }
        else
        {
            recuusiveBST(temp->right, newnode);
        }
    }
    else
    {
        if (temp->left == NULL)
        {
            temp->left = newnode;
        }
        else
        {
            recuusiveBST(temp->left, newnode);
        }
    }
}

void createBST(struct node **root)
{
    struct node *newnode = NULL;
    newnode = createNode();
    struct node *temp = *root;
    if (temp == NULL)
    {
        *root = newnode;
    }
    else
    {
        recuusiveBST(temp, newnode);
    }
}
void main()
{
    struct node *root = NULL;
    int choice;

    do
    {

        printf("Please Enter Your Choice: \n");
        printf("1. Create BST.\n");
        printf("2. Preorder Traversal.\n");
        printf("3. Inorder Traversal.\n");
        printf("4. Postorder Traversal.\n");
        printf("0. Exit.\n");
        printf("Choice = ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Thank you!!\n");
            break;
        case 1:
            createBST(&root);
            break;
        default:
            printf("Please Enter a Valid Choice.\n");
            break;
        }
    } while (choice != 0);
}