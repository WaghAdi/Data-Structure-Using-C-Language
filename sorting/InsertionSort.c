/*
Name:Wagh Aditya
batch:ppa09
topic:insertion Sort
*/

#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int empty = i;
        while (empty > 0 && arr[empty - 1] > temp)
        {
            arr[empty] = arr[empty - 1];
            empty--;
        }
        arr[empty] = temp;
    }
}
void main()
{
    int arr[100], n, min;
    printf("How many Elements want in array?\n");
    scanf_s("%d", &n);
    printf("Enter Array Elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &arr[i]);
    }
    printf("Unsorted Array Elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Sorted Array In Ascending Order Using Insertion Sort: ");
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
