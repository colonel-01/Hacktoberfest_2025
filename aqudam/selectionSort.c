//selection sort in C 
#include<stdio.h>

void printArr(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int* arr,int n){
    int min,index;
    for (int i = 0; i < n-1; i++)
    {
        min = arr[i];
        for (int j = i+1; j <= n-1; j++)
        {
           if (arr[j]<min)
           {
            min = arr[j];
            index = j;
           }
           
        }
        arr[index] = arr[i];
        arr[i] = min;
        
    }
    
    
}
int main(){
    int A[] = {22, 23, 3, 4, 99, 3};
    int n = 6;

    printArr(A);
    selectionSort(A,n);
    printArr(A);


return 0;
}