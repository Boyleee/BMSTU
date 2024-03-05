#include <stdio.h>
#include <math.h>


int strdiff(char *a, char *b){
    int diff = 0;
    int k = 0;
    int achi;
    int bchi;
    while (1) {
        int che = (a[k] == '\0') + (b[k] == '\0');
        switch (che) {
            case 1 : return diff;
            case 2 : return 0; 
        }
        achi = (int)a[k];
        bchi = (int)b[k];
        for (int i = 0; i < 8; i++) {
            if (((achi % (int)pow(2, i + 1))/pow(2, i)) != ((bchi % (int)pow(2, i + 1))/pow(2, i))) return diff + i;
        }
        k++;
        diff += 8;
    }
}
