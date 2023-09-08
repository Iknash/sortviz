#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "array_operations.h"
#include "sorting_algorithms.h"
#include "utilities.h"

int main(void) {
    int size, choice, speed;
    int exit = 0;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int rows = w.ws_row;

    int small_size_arr = rows / 4;
    int medium_size_arr = rows / 2;
    int large_size_arr = rows - 4;

    while (!exit) {
        clear_screen();

        printf("Choose array size:\n1. Small (%i)\n2. Medium (%i)\n3. Large (%i)\n", small_size_arr, medium_size_arr, large_size_arr);
        scanf("%d", &choice);

        clear_screen();

        switch(choice) {
            case 1: size = small_size_arr; break;
            case 2: size = medium_size_arr; break;
            case 3: size = large_size_arr; break;
            default: printf("Invalid choice, defaulting to Medium (%i)\n", medium_size_arr); size = medium_size_arr;
        }

        printf("Choose sorting speed:\n1. Slow\n2. Medium\n3. Fast\n");
        scanf("%d", &choice);

        clear_screen();

        switch(choice) {
            case 1: speed = 500000; break;
            case 2: speed = 200000; break;
            case 3: speed = 100000; break;
            default: printf("Invalid choice, defaulting to Medium\n"); speed = 200000;
        }

        printf("Choose sorting algorithm:\n1. Bubble Sort\n2. Merge Sort\n3. Quick Sort\n4. Bogo Sort\n5. Cocktail Shaker Sort\n");
        scanf("%d", &choice);

        clear_screen();

        int arr[size];
        generate_random_array(arr, size);

        display_array(arr, size);
        usleep(2000000);

        clear_screen();

        switch(choice) {
            case 1:
                bubble_sort(arr, size, speed);
                break;
            case 2:
                merge_sort(arr, 0, size - 1, speed);
                break;
            case 3:
                quick_sort(arr, 0, size - 1, speed);
                break;
            case 4:
                bogo_sort(arr, size, speed);
                break;
            case 5:
                cocktail_shaker_sort(arr, size, speed);
                break;
            default:
                printf("Invalid choice, defaulting to Bubble Sort\n");
                bubble_sort(arr, size, speed);
        }

        printf("Do you want to continue? (1: Yes, 0: No)\n");
        scanf("%d", &exit);
        exit = !exit;
    }

    return 0;
}
