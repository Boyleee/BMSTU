#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char **s, int n)
{
    int sizestr = 0;
    for (int i = 0; i < n; i++) {
        sizestr += strlen(s[i]);
    }
    char* concat_str = (char*)malloc((sizestr + 1) * sizeof(char));
    concat_str[0] = '\0';

    for (int i = 0; i < n; i++) {
        strcat(concat_str, s[i]);
    }
    return concat_str;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    char **str = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        str[i] = (char *)malloc(1002 * sizeof(char));
        fgets(str[i], 1002, stdin);
        for (int j = 0; str[i][j]; j++) {
           if (str[i][j] == '\n') {
               str[i][j] = '\0';
               break; 
           }
        }
    }

    char *result = concat(str, n);
    printf("%s", result);
    free(result);

    
    for (int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
