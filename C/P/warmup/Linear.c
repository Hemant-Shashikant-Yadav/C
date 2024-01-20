#include <stdio.h>

int main() {
    int size,i, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; 

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    int found = 0;

    for ( i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("Element found at index %d\n", i);
            break; 
        }
    }

    if (!found) {
        printf("Element not found in the array\n");
    }

    return 0;
}