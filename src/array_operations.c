#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }
}

void display_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}
