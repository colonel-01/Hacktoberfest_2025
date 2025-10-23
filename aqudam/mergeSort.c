// Merge Sort in C
#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    int k = 0;
    // int b[high+1];
    int *b = (int *)malloc((high-low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else{
            b[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k] = arr[j];
        k++;
        j++;
    }
    
    for (int h = 0; h < k; h++)
    {
        arr[low + h] = b[h];
    }
    // printArr(arr,6);
    free(b);
}

void mergeSort(int arr[],int low, int high){
    
    if (low<high)
    {
        int mid = (high+low)/2;
    
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high);
    }
}

int main()
{

    int A[] = {22, 23, 3, 4, 99, 18};
    int n = sizeof(A) / sizeof(int);

    printArr(A, n);
    mergeSort(A, 0,n-1);
    printArr(A, n);

    return 0;
}