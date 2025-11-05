
#include <stdio.h>

void sort(int a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) {
                int t=a[i]; a[i]=a[j]; a[j]=t;
            }
}

int optimalMerge(int files[], int n) {
    int total = 0;
    while(n > 1) {
        sort(files, n);
        int temp = files[0] + files[1];
        total += temp;
        files[0] = temp;
        for(int i=1;i<n-1;i++) files[i] = files[i+1];
        n--;
    }
    return total;
}

int main() {
    int files[] = {20, 30, 10, 5, 30};
    int n = 5;
    printf("Minimum total cost of merging = %d\n", optimalMerge(files, n));
    return 0;
}
