#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void countingSort(union Int32 array[], int size, int place) {
    union Int32 output[size];
    int count[256] = {0};
    
    for (int i = 0; i < size; i++)
        count[array[i].bytes[place]]++;

    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i].bytes[place]] - 1] = array[i];
        count[array[i].bytes[place]]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(union Int32 array[], int size) {
    for (int i = 0; i < 4; i++)
        countingSort(array, size, i);
}

int main() {
    int n;
    scanf("%d", &n);

    union Int32 *array = (union Int32 *)malloc(n * sizeof(union Int32));
    
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i].x);

    radixSort(array, n);

    for (int i = 0; i < n; i++)
        printf("%d ", array[i].x);
    printf("\n");

    free(array);
    
    return 0;
}
