/*
Name:Wagh Aditya
Topic:-Linear Serch.
*/

// *******************solution ******************

#include <stdio.h>

void linearSearch(int a[], int search, int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("element found\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("element not found\n");
    }
}

void main()
{
    int n, search;
    int a[100];
    printf("enter how many element want to add\n");
    scanf("%d", &n);
    printf("enter array element\n");
    //for loop to take array element from user
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //user input to search element
    printf("Enter element to be serch");
    scanf("%d", &search);
    linearSearch(a, search, n); //function call
}