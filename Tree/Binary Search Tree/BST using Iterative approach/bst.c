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

//searching in bst it takes lon(n) time to search element similar to binary search

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


//fun to find minimum element from tree means succesor of node which not having NULL at it's right 

struct node *findMin(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}


// fun to delete a node from bst

struct node *DeleteNode(struct node *root, int Data)
{
    struct node *temp = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > Data)
    {
        root->left = DeleteNode(root->left, Data);
    }
    else if (root->data < Data)
    {
        root->right = DeleteNode(root->right, Data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node *rightMin = findMin(root->right);
            root->data = rightMin->data;
            root->right = DeleteNode(root->right, rightMin->data);
            return root;
        }
    }
}

//function for finding inorder successor of any given node 
struct node *inOrdersuccessor(struct node *root, int Data, struct node *pre, struct node *succ)
{
    if (root == NULL)
        return NULL;
    else if (root->data > Data)
    {
        succ = root;
        inOrdersuccessor(root->left, Data, pre, succ);
    }
    else if (root->data < Data)
    {
        pre = root;
        inOrdersuccessor(root->right, Data, pre, succ);
    }
    else
    {
        if (root->right == NULL)
        {
            return succ;
        }
        else
        {
            succ = findMin(root->right);
            return succ;
        }
    }
}



void main()
{
    struct node *root = NULL;
    int choice;
    int data;
    int deleteData;
     int succData;
    struct node *pre = NULL;
    struct node *succ = NULL;
    struct node *successorPtr = NULL;
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
        if (choice == 7)
        {
            printf("Enter data of node whose successor want to find\n");
            scanf("%d", &succData);
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

            root = DeleteNode(root, deleteData);
            break;
        case 7:

         successorPtr = inOrdersuccessor(root, succData, pre, succ);
            printf("successor data=: %d\n", successorPtr->data);
            break;

        default:
            printf("Please Enter a Valid Choice.\n");
            break;
        }
    } while (choice != 0);
}