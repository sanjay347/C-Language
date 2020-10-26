#include <stdio.h>
#include <stdlib.h>

int find_max(int a[] , int n)
{
    int max = a[0];
    int i=1;
    while(i!=n)
    {
        if(a[i] > max)
        {
            max = a[i];
        }  
        i++;
    }
    return max;
}

void countsort(int a[],int n,int dgt,int base){

    int i;
    int arr_bucket[base];
    int temp[n];
    for(i=0;i<base;i++)
    {
        arr_bucket[i] = 0;
    }
        
    for(i=0;i<n;i++)
    {
        arr_bucket[(a[i]/dgt)%base]++;
    }

    for(i=1;i<base;i++)
    {
        arr_bucket[i]=arr_bucket[i]+arr_bucket[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        temp[arr_bucket[(a[i]/dgt)%base]-1] = a[i];
        arr_bucket[(a[i]/dgt)%base]--;
    }

    for(i=0;i<n;i++)
    {
        a[i] = temp[i];
    }
    
}

void radixsort(int a[] , int n, int base)
{
    int max;
    max = find_max(a, n);

    for(int dgt = 1; max/dgt > 0 ; dgt = dgt * base)
    {
        countsort(a, n , dgt, base);
    }
}

int main()
{
    int x, n, baseElement;
    printf("Enter the number of elements for Sorting: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements for Sorting: ");
    for(x = 0; x < n; x++)
    {
        scanf("%d",&a[x]);
    }
    printf("Enter the base that has to be used for Sorting: ");
    scanf("%d",&baseElement);
    radixsort(a , n ,baseElement);
    printf("The Sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}    
    