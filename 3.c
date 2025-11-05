#include <stdio.h>

struct Item {
    int value, weight;
};

void knapsack(struct Item items[], int n, int W) {
    float ratio[n];
    for(int i=0; i<n; i++) ratio[i] = (float)items[i].value / items[i].weight;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(ratio[i] < ratio[j]) {
                struct Item temp = items[i]; items[i] = items[j]; items[j] = temp;
                float t = ratio[i]; ratio[i] = ratio[j]; ratio[j] = t;
            }

    int curWeight = 0; float total = 0.0;
    for(int i=0; i<n; i++) {
        if(curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            total += items[i].value;
        } else {
            int remain = W - curWeight;
            total += ratio[i] * remain;
            break;
        }
    }
    printf("Maximum value in knapsack = %.2f\n", total);
}

int main() {
    struct Item items[] = {{60,10},{100,20},{120,30}};
    int W = 50;
    knapsack(items, 3, W);
    return 0;
}
