// Arlen Bennetti
// COP 3502
// March 8, 2024

#include <stdlib.h>
#include <stdio.h>

#define SIZE 9

void swap(int *i, int *j);
int bubbleSort(int arr[], int n);
int selectionSort(int arr[], int n);
void printArray(int arr[], int size, int numSwaps);

int main() {
    int array1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int n = sizeof(array1) / sizeof(array1[0]);
    int bubbleSwaps = bubbleSort(array1, n);
    int selectSwaps = selectionSort(array1, n);


    printf("array1: \n");
    printArray(array1, n, bubbleSwaps);
    

    printf("array2: \n");
    printArray(array1, n, selectSwaps);

    return 0;
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp; 
}

int bubbleSort(int arr[], int n) {
    int i, j;
    int bubbleSwaps = 0;

    for (i=0; i<n-1; i++) {

        for(j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                bubbleSwaps++;
            }
        }
    }

    return bubbleSwaps;
}

int selectionSort(int arr[], int n) {
    int i, j;
    int min;
    int selectSwaps = 0; 
  
    for (i = 0; i < n-1; i++) { 
        min = i; 
        for (j = i+1; j < n; j++) {
          if (arr[j] < arr[min]) 
            min = j; 
        }
  
           if(min != i) 
            swap(&arr[min], &arr[i]); 
            selectSwaps++;
    }

    return selectSwaps; 
}

void printArray(int arr[], int size, int numSwaps) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d: %d\n", arr[i], numSwaps);

    printf("total # of swaps: %d\n", numSwaps);
}