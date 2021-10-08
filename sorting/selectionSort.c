/*
Name:Wagh Aditya
batch:ppa09
topic:insertion Sort
*/

#include <stdio.h>
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void main()
{
    int arr[100], n, min;
    printf("How many Elements do you want in array?\n");
    scanf_s("%d", &n);
    printf("Enter Array Elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &arr[i]);
    }
    printf("Unsorted Array Elements\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Sorted Array In Ascending Order Using Selection Sort: ");
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}