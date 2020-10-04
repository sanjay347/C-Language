#include<stdio.h>
#include<stdlib.h>
int linear_search(int* arr, int n, int number){
    int found = -1;
    for(int i = 0; i< n; i++){
        if(arr[i] == number){
            found = i;
        }
    }
    return found;
}
int main(){
    printf("Enter array size\n");
    int n;
    int number;
    int res;
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements\n");
    for(int i = 0; i < n;i++)
        scanf("%d",(arr+i));
    printf("Enter number to be searched\n");
    
    scanf("%d",&number);    
    res = linear_search(arr,n,number);
    printf("Number %d occurs at index %d\n",number,res);
    free(arr);
    return 0;
}