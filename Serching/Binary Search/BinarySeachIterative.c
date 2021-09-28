#include <stdio.h>
void binarySearch(int a[], int low, int high, int search)
{
    int mid;
    mid = (low + high) / 2;
    while (low <= high)
    {
        //condition to cheak element is equal to mid or not
        if (a[mid] == search)
        {
            printf("element found\n");
            return;
        }
        //condition if element is smallar than mid element
        else if (a[mid] > search && search >= a[low])
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        //condition if element is greater than mid element
        else if (a[mid] < search && search <= a[high])
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        //element not found
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
    binarySearch(a, low, high, search); //function call
}