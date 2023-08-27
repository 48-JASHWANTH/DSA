#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[low],&arr[end]);
    return end;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf("\nSorted Array (Quick Sort): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
