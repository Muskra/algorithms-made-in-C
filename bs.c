#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool check_sort(int *values, size_t size) {
    for (int index = 0; index < size - 1; index++) {
        int actual = values[index];
        int next = values[index + 1];
        if (actual > next) {
            return true;
        }
    }
    return false;
}

void bubble_sort(int *values, size_t size) {
    do {
        for (int index = 0; index < size - 1; index ++) {
            int actual = values[index];
            int next = values[index + 1];
            if (actual > next) {
                values[index] = next;
                values[index + 1] = actual;
            }
        }
    } while (check_sort(values, size));
}

int main() {
    
    int values[] = {1, 2, 20, 19, 0, 4, 6, 13, 5, 17, 8, 12, 18, 7, 16, 3, 9, 11, 15, 14, 10};
    int size = sizeof(values)/sizeof(values[0]);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    bubble_sort(values, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}
