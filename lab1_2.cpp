#include <stdio.h>
#include "sort.h"  // Include the sorting header file to use sorting functions

// Linear Search function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

// Binary Search function (assumes array is sorted)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Element found at mid index
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr_size;

    // Get the size of the array from the user
    printf("Enter size of array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];

    // Get the array elements from the user
    printf("Enter array elements: \n");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubbleSort (you can use any of the sorting functions here)
    bubbleSort(arr_size, arr);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the target element to search for
    int target;
    printf("Enter number to search: ");
    scanf("%d", &target);

    // Perform Linear Search
    int result = linearSearch(arr, arr_size, target);
    if (result != -1) {
        printf("Linear Search: Element found at index %d\n", result);
    } else {
        printf("Linear Search: Element not found\n");
    }

    // Perform Binary Search
    result = binarySearch(arr, arr_size, target);
    if (result != -1) {
        printf("Binary Search: Element found at index %d\n", result);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}
