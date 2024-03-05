#include <stdio.h>
#include <string.h>
#define ull unsigned long long int

ull fibnum(int n) {
    if ((n == 1)||(n == 2)) return 1;
    else return (fibnum(n-2)+fibnum(n-1));
}

char *fibstr(int n) {
    char* str = (char*)malloc(fibnum(n) * sizeof(char));
    str[0] = '\0';
    if (n == 1) strcat(str, "a");
    else if (n == 2) strcat(str, "b");
    else strcat(strcat(str, fibstr(n-2)), fibstr(n -1));
    return str;
}

int main() {
    int n;
    scanf("%d", &n);    
    puts(fibstr(n));    
}