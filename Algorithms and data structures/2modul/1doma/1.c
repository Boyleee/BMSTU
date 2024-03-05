#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_overlap(char *a, char *b) {
    int max_overlap = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 1; i <= len_a && i <= len_b; i++) {
        if (strncmp(a + len_a - i, b, i) == 0) {
            max_overlap = i;
        }
    }
    return max_overlap;
}

int shortest_superstring(char **strings, int n) {
    while (n > 1) {
        int max_overlap = 0;
        int l, r;
        char *new_str;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int overlap = find_overlap(strings[i], strings[j]);
                if (overlap > max_overlap) {
                    max_overlap = overlap;
                    l = i;
                    r = j;
                }
            }
        }

        new_str = (char *)malloc(strlen(strings[l]) + strlen(strings[r]) - max_overlap + 1);
        strcpy(new_str, strings[l]);
        strcat(new_str, strings[r] + max_overlap);
        free(strings[l]);
        strings[l] = new_str;
        free(strings[r]);
        strings[r] = strings[n - 1];
        n--;
    }
    
    int len = strlen(strings[0]);
    for (int i = 0; i < n; ++i) {
        free(strings[i]);
    }
    return len;
}

int main() {
    int n;
    scanf("%d", &n);

    char **strings = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(1024);
        scanf("%1023s", strings[i]);
    }

    int result = shortest_superstring(strings, n);
    printf("%d\n", result);

    free(strings);
    return 0;
}