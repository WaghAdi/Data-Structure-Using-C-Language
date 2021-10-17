#include <stdio.h> //header file
#include <stdlib.h>

struct node //user defined data type structure
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode() //function to create node and return address of created node
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

// function to create binary search tree

void createBST(struct node **root)
{
    struct node *newnode = NULL;
    struct node *tempnode = *root;
    newnode = createNode();

    if (*root == NULL) //if node is first node only
    {
        *root = newnode;
    }
    else
    {
        while (tempnode != NULL)
        {
            if (newnode->data < tempnode->data)
            {
                if (tempnode->left == NULL)
                {
                    tempnode->left = newnode;
                    break;
                }
                else
                {
                    tempnode = tempnode->left;
                }
            }
            else
            {
                if (tempnode->right == NULL)
                {
                    tempnode->right = newnode;
                    break;
                }
                else
                {
                    tempnode = tempnode->right;
                }
            }
        }
    }
}

// preorder traversal code
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// inorder traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

//postorder traversal
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}

void searchNode(struct node *root, int searchData)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        printf("Data Not Found\n");
    }
    else
    {
        if (temp->data == searchData)
        {
            printf("Data Found\n");
        }
        else if (temp->data < searchData)
        {
            searchNode(temp->right, searchData);
        }
        else
        {
            searchNode(temp->left, searchData);
        }
    }
}

void main()
{
    struct node *root = NULL;
    int choice;
    int data;
    //menu driven programSS
    do
    {

        printf("Please Enter Your Choice: \n");
        printf("1. Create BST.\n");
        printf("2. Preorder Traversal.\n");
        printf("3. Inorder Traversal.\n");
        printf("4. Postorder Traversal.\n");
        printf("5.SearchNode n");
        printf("0. Exit.\n");
        printf("Choice = ");
        scanf("%d", &choice);
        if (choice == 5)
        {

            printf("enter data to serch\n");
            scanf("%d", &data);
        }

        switch (choice)
        {
        case 0:
            printf("Thank you!!!\n");
            break;
        case 1:
            createBST(&root);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            inOrder(root);
            break;
        case 4:
            postOrder(root);
            break;
        case 5:

            searchNode(root, data);
            break;
        default:
            printf("Please Enter a Valid Choice.\n");
            break;
        }
    } while (choice != 0);
}