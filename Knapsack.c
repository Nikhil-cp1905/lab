#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by value/weight ratio (descending)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j+1].value / items[j+1].weight;
            if (r1 < r2)
                swap(&items[j], &items[j+1]);
        }
    }
}

float knapsackGreedy(struct Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);

    float maxValue = knapsackGreedy(items, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}

