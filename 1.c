#include <stdio.h>

int binarySearch(int a[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] > key)
        return binarySearch(a, low, mid - 1, key);
    else
        return binarySearch(a, mid + 1, high, key);
}

int main() {
    int a[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 8;
    int result = binarySearch(a, 0, n - 1, key);
    (result == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result);
    return 0;
}
