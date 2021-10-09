/*
Name:Wagh Aditya
batch:ppa09
topic:Bubble Sort
*/

#include <stdio.h>

//sorting logic
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) //for loop to iterate element
    {
        for (int j = 0; j < n - i; j++) //swappint loop
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int arr[100], n;
    printf("Enter How many Elements you want in array?\n");
    scanf_s("%d", &n);
    printf("Enter Array Elements: \n");
    //taking array element as input from user
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &arr[i]);
    }
    printf("Unsorted Array: \n");
    for (int i = 0; i < n; i++) // print array elements.
    {
        printf("%d ", arr[i]);
    }
    printf("Sorted Array In Ascending Order Using Bubble Sort is: \n");
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}