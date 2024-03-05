#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

void swap(void* a, void *b, size_t width) {
    char tmp[width];
    memcpy(tmp, a, width);
    memcpy(a, b, width);
    memcpy(b, tmp, width);
}

int compare_a_count(const void* a, const void* b) {
    const char* str_a = *(const char**)a;
    const char* str_b = *(const char**)b;
    int a_count = 0;
    int b_count = 0;

    while (*str_a) {
        if (*str_a == 'a') {
            a_count++;
        }
        str_a++;
    }
    while (*str_b) {
        if (*str_b == 'a') {
            b_count++;
        }
        str_b++;
    }

    return a_count - b_count;
}

void siftDown(void *base, size_t start, size_t end, size_t width, int (*compare)(const void *, const void *)) {
    char *baseByte = (char *)base;
    size_t root = start;

    while ((root * 2 + 1) < end) {     
        size_t child = root * 2 + 1; 
        size_t toSwap = root;          

        if (compare(baseByte + toSwap * width, baseByte + child * width) < 0) {
            toSwap = child;
        }
        if ((child + 1 < end) && (compare(baseByte + toSwap * width, baseByte + (child + 1) * width) < 0)) {
            toSwap = child + 1;
        }
        if (toSwap == root) {
            return;  
        } else {
            swap(baseByte + root * width, baseByte + toSwap * width, width);
            root = toSwap;             
        }
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void*, const void*)) {
    size_t i;
    char *baseByte = (char *)base;

    for (i = (nel / 2); i > 0; i--) {
        siftDown(base, i - 1, nel, width, compare);
    }

    for (i = nel - 1; i > 0; i--) {
        swap(baseByte, baseByte + i * width, width);
        siftDown(base, 0, i, width, compare);
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    char** arr = malloc(n * sizeof(char*));
    
    for (int i = 0; i < n; ++i) {
        arr[i] = malloc(BUFFER_SIZE);
        fgets(arr[i], BUFFER_SIZE, stdin);
    }
    
    hsort(arr, n, sizeof(char*), compare_a_count);
    
    for (int i = 0; i < n; ++i) {
        printf("%s", arr[i]);
        free(arr[i]);
    }
    
    free(arr);
    return 0;
}
