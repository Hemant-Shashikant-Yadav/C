#include <stdio.h>
#include <stdlib.h>
int i;
struct Item {
    int weight;
    int value;
};

int compare(const void *a, const void *b) {
    double ratioA = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    
    return (ratioB > ratioA) - (ratioA > ratioB);
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double max_value = 0.0;
    int current_weight = 0;

    for (i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            max_value += items[i].value;
        } else {
            double remaining_capacity = capacity - current_weight;
            max_value += (items[i].value / (double)items[i].weight) * remaining_capacity;
            break;
        }
    }

    return max_value;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);


    double max_value = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in the knapsack = %.2lf\n", max_value);

    return 0;
}