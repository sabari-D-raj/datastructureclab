#include<stdio.h>

int n, a[50];

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partiation(int a[], int low, int high){
    int i = low, j = high, x = a[low];
    while(i < j){
        while(a[i] <= x && i < high)
            i++;
        while(a[j] > x && j > 0)
            j--;
        if(i < j)
            swap(a, i, j);
    }
    swap(a, low, j);
    return j;
}

void quicksort(int a[], int low, int high){
    if(low < high){                      
        int mid = partiation(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int main(){
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n-1);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}
