/*
Name:Wagh Aditya
Topic:-Linear Serch using two pointer Method
*/

// *******************solution ******************

#include <stdio.h>

void DoublePointeLinearSearch(int a[], int search, int n)
{
    int low = 0;  //set low to first element
    int high = n; //set high to last element
    int flag = 0; //for cheking element found or not
    while (low <= high)
    {
        if (a[low] == search || a[high] == search)
        {
            printf("Element found\n");
            flag = 1;
            break;
        }
        else
        {
            low++;
            high--;
        }
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
    DoublePointeLinearSearch(a, search, n); //function call
}