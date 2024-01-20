#include <stdio.h>

int main() {
    int n,i, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements in the array:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search for: ");
    scanf("%d", &key);

    int low = 0, high = n - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = 1;
            printf("Element %d found at index %d.\n", key, mid);
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}