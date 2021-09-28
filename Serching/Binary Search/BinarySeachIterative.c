#include <stdio.h>
void binarySearch(int a[], int low, int high, int search)
{
    int mid;
    mid = (low + high) / 2;
    while (low <= high)
    {

        if (a[mid] == search)
        {
            printf("element found\n");
            return;
        }
        else if (a[mid] > search && search >= a[low])
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else if (a[mid] < search && search <= a[high])
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            printf("element not found\n");
            return;
        }
    }
}
void main()
{
    int n, search;
    int a[100];
    printf("enter how many element want to add\n");
    scanf("%d", &n);
    printf("enter array element in sorted order\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to be serch");
    scanf("%d", &search);
    int low = 0;
    int high = n - 1;
    binarySearch(a, low, high, search);
}