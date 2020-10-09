#include <stdio.h>
 
int main()
{
    int i, n, temp;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++)
    {
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;
            while (arr[j] > arr[(j - 1) / 2])
            {
                temp = arr[(j-1)/2];
                arr[(j-1)/2] = arr[j];
                arr[j] = temp;
                j = (j - 1) / 2;
            }
        }
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        int j = 0, index;
        do
        {
            index = (2 * j + 1);
            if (arr[index] < arr[index + 1] && index < (i - 1))
            {
                index++;
            }
            if (arr[j] < arr[index] && index < i)
            {
                temp = arr[index];
                arr[index] = arr[j];
                arr[j] = temp;
            }
            j = index;
        } while (index < i);
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
