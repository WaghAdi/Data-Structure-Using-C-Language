#include<stdio.h>
void binarySearch(int a[],int low,int high,int search)
{
    int mid=(low+high)/2;
    if(a[mid]==search)
    {
        printf("element found\n");
        return;
    }
    else if(a[mid]>search && search >= a[low])
    {
        binarySearch(a,low,mid-1,search);
    }
    else if(a[mid]<search && search<=a[high])
    {
        binarySearch(a,mid+1,high,search);
    }
    else
    {
        printf("element not found\n");
        return;
    }
}
void main()
{   
    int n,search;
    int a[100];
    printf("enter how many element want to add\n");
   scanf("%d",&n);
   printf("enter array element in sorted order\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Enter element to be serch");
   scanf("%d",&search);
   int low=0;
   int high=n-1;
   binarySearch(a,low,high,search);

    
}