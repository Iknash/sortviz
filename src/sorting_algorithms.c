#include <stdlib.h>
#include <unistd.h>
#include "array_operations.h"
#include "utilities.h"

void bubble_sort(int arr[], int size, int speed) {
    for (int i = 0; i < size; ++i) {
        int swaps = 0;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                ++swaps;

                clear_screen();
                display_array(arr, size);
                usleep(speed);
            }
        }
        if (swaps == 0)
            break;
    }
}

void merge(int arr[], int l, int m, int r, int speed) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    clear_screen();
    display_array(arr, r + 1);
    usleep(speed);
}

void merge_sort(int arr[], int l, int r, int speed) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m, speed);
    merge_sort(arr, m + 1, r, speed);
    merge(arr, l, m, r, speed);
}

int partition(int arr[], int low, int high, int speed) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    clear_screen();
    display_array(arr, high + 1);
    usleep(speed);

    return (i + 1);
}

void quick_sort(int arr[], int low, int high, int speed) {
    if (low < high) {
        int pi = partition(arr, low, high, speed);

        quick_sort(arr, low, pi - 1, speed);
        quick_sort(arr, pi + 1, high, speed);
    }
}

int is_sorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void shuffle(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bogo_sort(int arr[], int size, int speed) {
    while (!is_sorted(arr, size)) {
        shuffle(arr, size);

        clear_screen();
        display_array(arr, size);
        usleep(speed);
    }
}


void cocktail_shaker_sort(int arr[], int size, int speed) {
    int swapped = 1;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;

                clear_screen();
                display_array(arr, size);
                usleep(speed);
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;

                clear_screen();
                display_array(arr, size);
                usleep(speed);
            }
        }

        ++start;
    }
}

