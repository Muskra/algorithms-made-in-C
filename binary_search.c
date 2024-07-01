#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

void print_array(int *values, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int binary_search(int target, int *values, size_t size) {
    int min = 0;
    int max = size - 1;
    int check = 0;

    do {
        if (min > max) {
            fprintf(stderr, "value: '%d', does not exist in the array.\n", target);
            exit(0);
        }

        int center = (min + max) / 2;

        if ((max - min) == 1) {
            check = center;
        } else {
            check = center - 1;
        }

        if (values[check] < target) {
            min = center + 1;
        } else if (values[check] > target) {
            max = center - 1;
        } else {
            break;
        }

    } while (values[check] != target);

    return check;
}

int main() {
    
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(values) / sizeof(values[0]);

    print_array(values, size);
    
    int search_for = 11;
    int index = binary_search(search_for, values, size);

    printf("Value: %d, is at position: %d\n", search_for, index);
    
    int new_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int new_size = sizeof(new_values) / sizeof(new_values[0]);
    print_array(new_values, new_size);
    index = binary_search(search_for, new_values, new_size);
}
