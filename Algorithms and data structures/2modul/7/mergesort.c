#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isComposedOfPrefixes(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int i = 0, j = 0;

    while (i < tLen) {
        if (s[j] == t[i]) {
            i++;
            j++;
            // Если j достигло конца s, начинаем с начала s
            if (j == sLen) j = 0;
        }
        else {
            if (j > 0) {
                // Если не совпадает, но мы уже начали сравнение,
                // значит не все t состоит из префиксов s
                return false;
            }
            i++;
        }
        // Если символ из t не совпал с первым символом s и j еще не сдвинулся,
        // т.е., не было ни одного совпадения
        if (j == 0 && i >= 1 && s[0] != t[i-1]) {
            return false;
        }
    }
    
    // Проверяем, что последний проверенный символ t завершился на префиксе s
    return j > 0;
}

int main() {
    char s[1001], t[1001]; // Предполагаем, что входные строки не превысят 1000 символов

    printf("Enter string S: ");
    // Получаем строки S и T
    scanf("%1000s", s);
    printf("Enter string T: ");
    scanf("%1000s", t);

    // Выполняем проверку и выводим результат
    if (isComposedOfPrefixes(s, t)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
