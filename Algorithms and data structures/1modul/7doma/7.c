#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void erat(bool arr[], long long int n) {
    for (long long int i = 2; i * i < n; i++) {
        if (!arr[i]) {
            for (long long int j = i * i; j < n; j += i) {
                arr[j] = true;
            }
        }
    }
}

int main() {
    long long int num;
    scanf("%lld", &num);
    num = abs(num);
    bool *arr = (bool*)malloc(sizeof(bool) * (num + 1));

    for (long long int i = 0; i <= num; i++) {
        arr[i] = false;
    }
    
    erat(arr, num + 1);
    
    long long int max_prime = 0;
    for (long long int i = num; i > 1; i--) {
        if (!arr[i]&&(num % i == 0)) {
            max_prime = i;
            break;
        }
    }

    printf("%lld\n",max_prime);

    free(arr);
    return 0;
}
