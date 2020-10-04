#include<stdio.h>
#include<stdlib.h>
int binary_search(int* arr, int n, int number){
    int low  = 0; int high = n -1; int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == number){
            return mid;
        }else if(arr[mid] > number){
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    printf("Enter array size\n");
    int n;
    int number;
    int res;
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements in ascending order\n");
    for(int i = 0; i < n;i++)
        scanf("%d",(arr+i));
    printf("Enter number to be searched\n");
    
    scanf("%d",&number);    
    res = binary_search(arr,n,number);
    printf("Number %d occurs at index %d\n",number,res);
    free(arr);
    return 0;
}