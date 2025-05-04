#include <stdio.h>
#include <stdlib.h>

// Bubble Sort function
void bubbleSort(int x, int a[]) {
    int num = x;
    int temp = 0;
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num - 1 - i; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Selection Sort function
void selectionSort(int x, int a[]) {
    int num = x;
    for(int i = 0; i < num; i++) {
        int temp = a[i];
        int pos = i;
        for(int j = i + 1; j < num; j++) {
            if(a[j] < temp) {
                temp = a[j];
                pos = j;
            }
            a[pos] = a[i];
            a[i] = temp;
        }
    }
}

// Insertion Sort function
void insertionSort(int x, int a[]) {
    int num = x;
    for(int i = 1; i < num; i++) {
        int temp = a[i];
        int pos = i;
        while(pos > 0 && a[pos - 1] > temp) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = temp;
    }
}

// Function to exit the program (optional, if used)
void exitFunc() {
    exit(0);
}
