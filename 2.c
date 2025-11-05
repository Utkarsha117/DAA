#include <stdio.h>

void merge(int *a, int *left, int leftCount, int *right, int rightCount) {
    int i=0,j=0,k=0;
    while(i<leftCount && j<rightCount) {
        if(left[i] < right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while(i<leftCount) a[k++] = left[i++];
    while(j<rightCount) a[k++] = right[j++];
}

void mergeSort(int *a, int n) {
    if(n < 2) return;
    int mid = n/2;
    int left[mid], right[n - mid];
    for(int i=0;i<mid;i++) left[i] = a[i];
    for(int i=mid;i<n;i++) right[i - mid] = a[i];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(a, left, mid, right, n - mid);
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a, n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    return 0;
}
