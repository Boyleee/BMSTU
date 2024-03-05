#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256
#define BUFFER_SIZE 1000

void sort_str(char *str) {
    int count[MAX_CHAR] = {0};
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        count[(int)str[i]]++;
    }

    int index = 0;
    for (i = 0; i < MAX_CHAR; i++) {
        while (count[i] > 0) {
            str[index++] = (char)i;
            count[i]--;
        }
    }
}

int main() {
    char str[BUFFER_SIZE];
    fgets(str, BUFFER_SIZE, stdin);

    str[strcspn(str, "\n")] = 0;

    sort_str(str);

    printf("%s\n", str);
    return 0;
}
