#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b)) {
            void* p = base;
            void max;
            void* pmax = &max;
            int num = 0;
            memcpy(pmax, p; width);
            for (int i = 1; i < nel + 1; i++) {
                if (compare(p + width * i, pmax > 0)) {
                    memcpy(pmax, p + width * i; width);
                    num = i;
                }
            }
            return i;
        }