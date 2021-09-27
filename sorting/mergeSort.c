#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int b[100];
    int i = low;
    int j = mid + 1;
    int k = 0;
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
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }




    int l=0;
    for(int i=low;i<=high;i++)
    {
        a[i]=b[l];
        l++;
    }
}








void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


void main()
{
    int n;
    int a[100];
    printf("enter how many element you want to add\n");
    scanf("%d", &n);
    printf("enter element\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("before sorting array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int l = 0;
    int h = n - 1;

    mergeSort(a, l, h);
    printf("\nSorted Array In Ascending Order Using Merge Sort: ");
    for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}