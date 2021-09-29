/*
Name:Wagh Aditya
Topic:-Quick Sort 
*/

// *******************solution ******************

#include <stdio.h>

void quickSort(int a[], int l, int h)
{
    int pivot = a[l];
    int low = l + 1;
    int high = h;
    while (low <= high)
    {
        while (pivot > a[low])
        {
            low++;
        }
        while (pivot < a[high])
        {
            high--;
        }
        if (low <= high)
        {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
            low++;
            high--;
        }
    }
    int temp = a[l];
    a[l] = a[high];
    a[high] = temp;
    if (l < high)
    {
        quickSort(a, l, high - 1);
    }
    if (low < h)
    {
        quickSort(a, low, h);
    }
}
void main()
{
    int n;
    int a[100];
    printf("enter how many element want in array\n");
    scanf("%d", &n);
    printf("Enter array element\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("array before sorting is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    int l = 0;
    int h = n - 1;

    quickSort(a, l, h);
    printf("\n");
    printf("array after sorting is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}