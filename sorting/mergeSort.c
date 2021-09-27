/*
Name:-Wagh Aditya.
topic:-Sorting and serching
Merge Sort Implmentation
*/

#include <stdio.h>
void merge(int a[], int low, int mid, int high)
{
    int b[100];  //temparary array for storing sorted element
    int i = low; //point to first element of current boundry
    int j = mid + 1;
    int k = 0;
    //loop to sort and store element of array in temparary array
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    //copy remaing element of till mid
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    //copy remaing element of til last
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    int l = 0;
    //replacing element in original array with temparary array
    for (int i = low; i <= high; i++)
    {
        a[i] = b[l];
        l++;
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;      //finding middle element
        mergeSort(a, low, mid);      //recursive call for first half
        mergeSort(a, mid + 1, high); //recursive call for second half
        merge(a, low, mid, high);    //fuction which sort the element of givne range i.e.form low to high
    }
}

void main()
{
    int n;
    int a[100]; //array initialization
    printf("enter how many element you want to add\n");
    scanf("%d", &n);
    //taking user input in array
    printf("enter element\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("before sorting array\n"); //printing given array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int l = 0;
    int h = n - 1;

    mergeSort(a, l, h); //calling merge sort function
    printf("\nSorted Array In Ascending Order Using Merge Sort: ");
    for (int i = 0; i < n; i++) // For loop to print sorted array..
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}