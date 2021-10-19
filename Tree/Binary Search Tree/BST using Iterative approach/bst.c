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

struct node *findMin(struct node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        findMin(root->left);
    }
    return root;
}

struct node *deleteBST(struct node *root, int Data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > Data)
    {
        deleteBST(root->left, Data);
    }
    else if (root->data < Data)
    {
        deleteBST(root->right, Data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node *rightMin = findMin(root->right);
            root->data = rightMin->data;
            root->right = deleteBST(root->right, rightMin->data);
        }
        return root;
    }
}

void main()
{
    struct node *root = NULL;
    int choice;
    int data;
    int deleteData;
    //menu driven programSS
    do
    {

        printf("Please Enter Your Choice: \n");
        printf("1. Create BST.\n");
        printf("2. Preorder Traversal.\n");
        printf("3. Inorder Traversal.\n");
        printf("4. Postorder Traversal.\n");
        printf("5.SearchNode\n");
        printf("6.Delete Node\n");
        printf("0. Exit.\n");
        printf("Choice = ");
        scanf("%d", &choice);
        if (choice == 5)
        {

            printf("enter data to serch\n");
            scanf("%d", &data);
        }
        if (choice == 6)
        {

            printf("enter data to delte\n");
            scanf("%d", &deleteData);
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
        case 6:

            root = deleteBST(root, deleteData);
            break;
        default:
            printf("Please Enter a Valid Choice.\n");
            break;
        }
    } while (choice != 0);
}