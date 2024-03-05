#include <stdio.h>

unsigned long long int fyb(int n) {
    unsigned long long int f0 = 1, f = 1;
    for (int i = 0; i < n - 1; i++) {
        f = f + f0;
        f0 = f - f0;
    }
    return f;
}
void fybsys(unsigned long long int a) {
    if ((a == 0)||(a == 1)) {
        printf("%d", a);
        return;
    }
    int k = 1;
    while (a > fyb(k)) k++;
    k--;
    for (int i = k; i > 0; i--) {
        if (a >= fyb(i)) {
            printf("1");
            a -= fyb(i);
        }
        else printf("0");
    }
}
int main() {
    unsigned long long int a;
    scanf("%llu", &a);
    fybsys(a);
    return 0;
}