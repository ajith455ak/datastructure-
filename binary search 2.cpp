#include <stdio.h>
int binarySearch(int arr[], int size, int selement) {
    int first = 0;
    int last = size - 1;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (arr[mid] == selement) {
            return mid;
        } else if (arr[mid] < selement) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return -1;
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    int selement;
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &selement);
    int index = binarySearch(arr, size, selement);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}

